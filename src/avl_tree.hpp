#include "bst.hpp"

#ifndef AVL_LEAF
#define AVL_LEAF
///Tree leaf that is used in avl tree
///In addition it has height
template<typename T>
class avl_leaf : public leaf<T>{
public:
    int height{};
};
#endif

#ifndef AVL_TREE_HPP
#define AVL_TREE_HPP



///Self Balancing Binary Search Tree with sorted_list interface. 
///It's using node like objects.
template<typename T> 
class avl_tree : public bst<T> {
public:
    avl_tree() = default;;
    ~avl_tree();
    /// \see sorted_list
    void insert(T value) override;
    /// \see sorted_list
    T pop_front() override;
    /// \see sorted_list
    T pop_back() override;
private:
    /// Recursive function for inserting a value at its spot
    /// \param curr currently processed leaf
    /// \param value
    void insert_rec(leaf<T>* curr,T value);

    //Performs right rotation on Tree
    /// \param sub_tree_high is upper element of rotation
    void rotate_right(avl_leaf<T>* sub_tree_high);

    //Performs left rotation on Tree
    /// \param sub_tree_high is upper element of rotation
    void rotate_left(avl_leaf<T>* sub_tree_high);
};

/// namespace with things that doesnt fit in class
namespace utils{
    template<typename T>
    int get_height(avl_leaf<T>* node);
    template<typename T>
    int calc_balance(avl_leaf<T>* node);
    template<typename T>
    void update_height(avl_tree<T>* node);

    /// Gets height of leaf, if is not present returns 0
    /// \param node avl_leaf<T>* points to leaf from which height is taken
    /// \return int with height of subtree or 0
    template<typename T>
    int get_height(avl_leaf<T>* node){
        return (node == nullptr) ? 0 : node->height;
    }
    /// calculate balance value in node for self balancing avl
    /// \param node Leaf of which balance value should be calculated
    /// \return int with balance
    template<typename T>
    int calc_balance(avl_leaf<T>* node){
        return get_height(static_cast<avl_leaf<T>*>(node->left)) - get_height(static_cast<avl_leaf<T>*>(node->right));
    }

    /// Updates heights based on subtrees below. It needs to be run with <T> at end.
    /// \tparam T type of objects in avl_leaf
    /// \param node pointer to avl_leaf of which height will be updated
    template<typename T>
    void update_height(avl_leaf<T>* node){
        if(node == nullptr) return;
        node->height = 1 + max(get_height(static_cast<avl_leaf<T>*>(node->left)), get_height(static_cast<avl_leaf<T>*>(node->right)));
    }
}

template<typename T>
void avl_tree<T>::rotate_right(avl_leaf<T>* sub_tree_high)
{
    auto* sub_tree_lw = static_cast<avl_leaf<T>*>(sub_tree_high->left);

    sub_tree_high->left = sub_tree_lw->right;
    sub_tree_lw->right = sub_tree_high;

    sub_tree_lw->parent = sub_tree_high->parent;

    sub_tree_high->parent = sub_tree_lw;

    if ( sub_tree_lw->parent ){
        if ( sub_tree_lw->parent->left == sub_tree_high ) sub_tree_lw->parent->left = sub_tree_lw;
        else sub_tree_lw->parent->right = sub_tree_lw;
    }
    else this->head = sub_tree_lw;

    utils::update_height<T>(sub_tree_high);
    utils::update_height<T>(sub_tree_lw);
}

template<typename T>
void avl_tree<T>::rotate_left(avl_leaf<T>* sub_tree_high)
{
    auto* sub_tree_lw = static_cast<avl_leaf<T>*>(sub_tree_high->right);

    sub_tree_high->right = sub_tree_lw->left;
    sub_tree_lw->left = sub_tree_high;

    sub_tree_lw->parent = sub_tree_high->parent;

    sub_tree_high->parent = sub_tree_lw;

    if ( sub_tree_lw->parent ){
        if ( sub_tree_lw->parent->left == sub_tree_high ) sub_tree_lw->parent->left = sub_tree_lw;
        else sub_tree_lw->parent->right = sub_tree_lw;
    }
    else this->head = sub_tree_lw;

    utils::update_height<T>(sub_tree_high);
    utils::update_height<T>(sub_tree_lw);
}

template<typename T>
void avl_tree<T>::insert(T value)
{
    if(this->head == nullptr){
        auto* curr = new avl_leaf<T>();
        curr->value = value;
        curr->height = 1;
        this->head = curr;
        container::size_=1;
    }
    else{
        insert_rec(this->head,value);
        container::size_ ++;
    }
}

template<typename T>
void avl_tree<T>::insert_rec(leaf<T>* curr, T value)
{

    if (value > curr->value){
        if (curr->right == nullptr){
            auto *ne = new avl_leaf<T>();
            ne->parent = curr;
            ne->value = value;
            ne->height = 1;

            curr->right = ne;
        }
        else
            insert_rec(curr->right, value);
    }
    else if (value < curr->value){
        if (curr->left== nullptr){
            auto *ne = new avl_leaf<T>();
            ne->value = value;
            ne->parent = curr;
            ne->height = 1;

            curr->left = ne;
        }
        else
            insert_rec(curr->left, value);
    }
    else{
        return;
    }

    //Type conversion
    auto* curr_leaf = dynamic_cast<avl_leaf<T>*>(curr);


    // Recalculate height
    curr_leaf->height = 1 + utils::max(utils::get_height(dynamic_cast<avl_leaf<T>*>(curr_leaf->right)),
                                       utils::get_height(dynamic_cast<avl_leaf<T>*>(curr_leaf->left)));

    //Calc balance
    int balance = utils::calc_balance(dynamic_cast<avl_leaf<T>*>(curr_leaf));

    //Right and left
    if (balance > 1 && value < curr_leaf->left->value) rotate_right(dynamic_cast<avl_leaf<T>*>(curr_leaf));
    else if (balance < -1 && value > curr_leaf->right->value) rotate_left(dynamic_cast<avl_leaf<T>*>(curr_leaf));

    //Left - right
    else if (balance > 1 && value > curr_leaf->left->value){
        rotate_left(dynamic_cast<avl_leaf<T>*>(curr_leaf->left));
        rotate_right(dynamic_cast<avl_leaf<T>*>(curr_leaf));
    }

    //Right - left
    else if (balance < -1 && value < curr_leaf->right->value){
        rotate_right(dynamic_cast<avl_leaf<T>*>(curr_leaf->right));
        rotate_left(dynamic_cast<avl_leaf<T>*>(curr_leaf));
    }
}

template<typename T>
T avl_tree<T>::pop_front()
{
    T ret;
    leaf<T>* cp2 = this->head;
    leaf<T>* cp = nullptr;
    while (cp2->left != nullptr)
    {
        cp = cp2;
        cp2 = cp2->left;
    }
    ret = cp2 -> value;
    if (cp == nullptr){
        //means cp2 is this->head still
        this->head = this->head -> right;
    }
    else{
        cp -> left = cp2->right;
    }
    delete cp2;
    container::size_--;
    return ret;
}

template<typename T>
T avl_tree<T>::pop_back()
{
    T ret;
    leaf<T>* cp2 = this->head;
    leaf<T>* cp = nullptr;
    while (cp2->right != nullptr)
    {
        cp = cp2;
        cp2 = cp2->right;
    }
    ret = cp2 -> value;
    if (cp == nullptr){
        this->head = this->head->right;
    }
    else{
        cp -> right = cp2->left;
    }
    delete cp2;
    container::size_--;
    return ret;
}

template<typename T>
avl_tree<T>::~avl_tree() {
    this->clear();
}


#endif

