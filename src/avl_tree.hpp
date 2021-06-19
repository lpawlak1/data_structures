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
    /// Inserts element T in tree
    /// \param value T type, note it will not be inserted if element with exact same value exists in tree
    /// \see sorted_list
    void insert(T value) override;
    /// Removes item from the front of tree
    /// \see sorted_list
    T pop_front() override;
    /// Removes item from the back of tree
    /// \see sorted_list
    T pop_back() override;

    /// Removes leaf if exists in tree, based on key
    /// \param key if value which is in tree, type T
    /// \return bool informing whether leaf was found and removed
    bool remove_by_key(T key);
    /// Removes leaf if proper index is present aka index >=0 and index < container size
    /// \param index in sorted list
    void remove_by_index(int index);

    /// Simple function to return head of tree
    /// \return pointer to avl_tree with head of tree
    avl_leaf<T>* get_data_avl(){return static_cast<avl_leaf<T>*>(this->head);};

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


    /// Finds leaf that is smallest of bigger leaves
    /// \param leaf of which leaf the successor should be found
    /// \return pointer to such next leaf
    avl_leaf<T>* find_succesor(avl_leaf<T>* leaf);

    /// Removes leaf from tree
    /// \param leaf is pointer to leaf that should be removed
    void remove_leaf(avl_leaf<T> *leaf);

    /// Rebalances th leaf and everything from it to parent, so this can be called to balance whole tree from child most node
    /// \param curr leaf from which balancing should start
    void rebalance_up(avl_leaf<T> *curr);

    /// Removes head of tree, it's a little other than remove_leaf(avl_leaf<T>* leaf)
    void remove_head();
};

/// namespace with things that doesnt fit in class
namespace utils{
    template<typename T>
    int get_height(avl_leaf<T>* node);
    template<typename T>
    int calc_balance(avl_leaf<T>* node);
    template<typename T>
    void update_height(avl_leaf<T>* node);
    template<typename T>
    void swap_avl_node(avl_leaf<T>* f1, avl_leaf<T>* f2);

    /// Gets height of leaf, if is not present returns 0
    /// \param node avl_leaf<T>* points to leaf from which height is taken
    /// \return int with height of subtree or 0
    template<typename T>
    int get_height(avl_leaf<T>* node){
        return (node == nullptr) ? 0 : node->height;
    }

    /// Calculate balance value in node for self balancing avl.
    /// If node if nullptr returns 0.
    ///
    /// \param node Leaf of which balance value should be calculated
    /// \return int with balance
    template<typename T>
    int calc_balance(avl_leaf<T>* node){
        if (node == nullptr) return 0;
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

    /// Swaps two elements' values in avl tree
    /// \param f1 is pointer to first leaf
    /// \param f2 is pointer to second leaf
    template<typename T>
    void swap_avl_node(avl_leaf<T>* f1, avl_leaf<T>* f2){
        auto copy_value = f1->value;
        f1->value = f2->value;
        f2->value = copy_value;
    }
}

template<typename T>
void avl_tree<T>::rotate_right(avl_leaf<T>* sub_tree_high)
{
    auto* sub_tree_lw = static_cast<avl_leaf<T>*>(sub_tree_high->left);

    sub_tree_high->left = sub_tree_lw->right;
    if ( sub_tree_lw->right != nullptr){
        sub_tree_lw->right->parent = sub_tree_high;
    }
    sub_tree_lw->right = sub_tree_high;

    sub_tree_lw->parent = sub_tree_high->parent;

    sub_tree_high->parent = sub_tree_lw;

    if ( sub_tree_lw->parent  != nullptr){
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
    if ( sub_tree_lw->left!= nullptr){
        sub_tree_lw->left->parent = sub_tree_high;
    }
    sub_tree_lw->left = sub_tree_high;

    sub_tree_lw->parent = sub_tree_high->parent;

    sub_tree_high->parent = sub_tree_lw;

    if ( sub_tree_lw->parent != nullptr){
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

            rebalance_up(static_cast<avl_leaf<T>*>(curr));
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

            rebalance_up(static_cast<avl_leaf<T>*>(curr));
        }
        else
            insert_rec(curr->left, value);
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

template<typename T>
avl_leaf<T> *avl_tree<T>::find_succesor(avl_leaf<T> *leaf) {
    auto* ans = leaf->right;
    while (ans->left != nullptr) ans = ans->left;
    return static_cast<avl_leaf<T>*>(ans); // This needs to be avl_leaf, i fit doesnt then somethings wrong
}

template<typename T>
bool avl_tree<T>::remove_by_key(T key) {
    auto* leaf = this->find_leaf(this->head,key);
    if(leaf == nullptr) return false;

    if (leaf != this->head)
        remove_leaf(static_cast<avl_leaf<T> *>(leaf));
    else
        this->remove_head();
    container::size_ --;
    return true;
}

template<typename T>
void avl_tree<T>::remove_by_index(int index){
    if(index >= container::size_ || index < 0) return;

    int* curr_ind = new int(); // Needed for traverse
    (*curr_ind) = 0;
    auto* leaf = traverse(this->head,curr_ind, index); // finds item by index in sorted_list
    delete curr_ind;

    //Leaf will be found as this first line checks whether the index is in tree

    if(leaf == this->head) this->remove_head();
    else remove_leaf(static_cast<avl_leaf<T> *>(leaf));

    container::size_ --;
}

template<typename T>
void avl_tree<T>::remove_head(){
    auto* leaf = this->head;
    if(leaf == nullptr) return;

#ifdef GTEST_INCLUDE_GTEST_GTEST_H_
    printf("%d\n",leaf->value);
#endif

    if (leaf->right == nullptr && leaf->left == nullptr){ // both left and right node is empty
        this->head = nullptr;
        delete leaf;
    }
    else if (leaf->left == nullptr){ // left node is empty
        auto* cp  = this->head->right;
        cp->parent = nullptr;
        this->head = cp;
        delete leaf;
    }
    else if (leaf->right == nullptr){ // right node is empty
        auto* cp  = leaf->left;
        cp->parent = nullptr;
        this->head = cp;
        delete leaf;
    }
    else{
        auto* succesor = find_succesor(static_cast<avl_leaf<T>*>(leaf));
#ifdef GTEST_INCLUDE_GTEST_GTEST_H_
        {
            using namespace std;
            cout << leaf->value << ", " << succesor->value << endl;
        }
#endif
        utils::swap_avl_node<T>(static_cast<avl_leaf<T> *>(leaf), succesor);
        remove_leaf(succesor);
        rebalance_up(static_cast<avl_leaf<T> *>(leaf));
    }

}


template<typename T>
void avl_tree<T>::remove_leaf(avl_leaf<T> *leaf){
    if(leaf == nullptr) return;

#ifdef GTEST_INCLUDE_GTEST_GTEST_H_
    printf("%d\n",leaf->value);
#endif

    if (leaf->right == nullptr && leaf->left == nullptr){ // both left and right node is empty
        if (leaf->parent->left == leaf){
            leaf->parent->left = nullptr;
        }
        else{
            leaf->parent->right = nullptr;
        }
        auto* pare = leaf->parent;
        delete leaf;
        rebalance_up(static_cast<avl_leaf<T> *>(pare));
    }
    else if (leaf->left == nullptr){ // left node is empty
        if (leaf->parent->left == leaf){
            leaf->parent->left = leaf->right;
        }
        else{
            leaf->parent->right = leaf->right;
        }
        auto* pare = leaf->parent;
        leaf->right->parent = pare;
        delete leaf;
        rebalance_up(static_cast<avl_leaf<T> *>(pare));
    }
    else if (leaf->right == nullptr){ // right node is empty
        if (leaf->parent->left == leaf){
            leaf->parent->left = leaf->left;
        }
        else{
            leaf->parent->right = leaf->left;
        }
        auto* pare = leaf->parent;
        leaf->left->parent = pare;
        delete leaf;
        rebalance_up(static_cast<avl_leaf<T> *>(pare));
    }
    else{
        auto* succesor = find_succesor(leaf);
#ifdef GTEST_INCLUDE_GTEST_GTEST_H_
        {
            using namespace std;
            cout << leaf->value << ", " << succesor->value << endl;
        }
#endif
        utils::swap_avl_node<T>(leaf, succesor);
        remove_leaf(succesor);
        rebalance_up(static_cast<avl_leaf<T> *>(leaf));
    }

}

template<typename T>
void avl_tree<T>::rebalance_up(avl_leaf<T> *curr){
    if(curr == nullptr) return;
    //Type conversion
    auto* curr_leaf = dynamic_cast<avl_leaf<T>*>(curr);
    //load parent
    auto* parent = dynamic_cast<avl_leaf<T>*>(curr->parent);


    // Recalculate height
    curr_leaf->height = 1 + utils::max(utils::get_height(dynamic_cast<avl_leaf<T>*>(curr_leaf->right)),
                                       utils::get_height(dynamic_cast<avl_leaf<T>*>(curr_leaf->left)));

    //Calc balance
    int balance = utils::calc_balance(dynamic_cast<avl_leaf<T>*>(curr_leaf));
    int right_balance = utils::calc_balance(dynamic_cast<avl_leaf<T>*>(curr_leaf->right));
    int left_balance = utils::calc_balance(dynamic_cast<avl_leaf<T>*>(curr_leaf->left));

    //Right and left
    if (balance > 1 && left_balance >= 0) rotate_right(dynamic_cast<avl_leaf<T>*>(curr_leaf));
    else if (balance < -1 && right_balance <= 0) rotate_left(dynamic_cast<avl_leaf<T>*>(curr_leaf));

    //Left - right
    else if (balance > 1 && left_balance < 0){
        rotate_left(dynamic_cast<avl_leaf<T>*>(curr_leaf->left));
        rotate_right(dynamic_cast<avl_leaf<T>*>(curr_leaf));
    }

    //Right - left
    else if (balance < -1 && right_balance > 0){
        rotate_right(dynamic_cast<avl_leaf<T>*>(curr_leaf->right));
        rotate_left(dynamic_cast<avl_leaf<T>*>(curr_leaf));
    }

    if (parent != nullptr)
        rebalance_up(parent);
}

#endif

