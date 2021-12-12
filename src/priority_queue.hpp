#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include "vector.hpp"
#include "container.h"


/// Element which is used in priority_queue->vector as element
/// \tparam T type of data stored in `value` field
template<typename T>
class heap_node{
public:
    /// The only constructor as nodes are created in priority_queue with every field in it
    /// names in contructor as used under the same name in class (pq is private)
    /// \param pq pointer to heap in which heap_node is stored
    /// \param index on which place element is stored in priority_queue->vector
    /// \param value proper value of element
    heap_node(void* pq, int index, T value){
        this->value = value;
        this->index = index;
        this->pq = pq;
    }


    T value;
    int index = 0;

    /// Changes value in node and rebalances in heap
    /// \param new_value value that is replacement for previous value
    /// \return value that was previously stored in node
    T change_priority(T new_value);
    int parent() {return (this->index-1) / 2;}
    int left() {return (this->index*2)+1;}
    int right() {return (this->index*2)+2;}

    ~heap_node() = default;
private:
    void* pq = nullptr;

};


/// Priority queue based on heap which is based on vector which holds heap_node<T>*
/// Values don't need to be unique.
/// If no min_heap value is passed to constructor it's made to be min heap
/// \see heap_node
/// \see vector
/// \tparam T type of stored elements it needs to implements `operator<()` and `operator>()`
template<typename T>
class priority_queue : public vector<heap_node<T>*>{
public:
    /// Default constructor
    priority_queue() = default;;

    /// Constructor with initial_size of array containing elements
    /// \param initial_size int with size of array at start
    explicit priority_queue(int initial_size) : vector<heap_node<T>*>(initial_size) {}

    /// Constructor with both arguments initial_size and min_heap
    /// \param initial_size int with size of array at start
    /// \param min_heap bool whether this should be min heap (true) or max heap (false)
    priority_queue(int initial_size, bool min_heap) : vector<heap_node<T>*>(initial_size) {
        this->min_heap = min_heap;
    }

    /// Constructor with one bool information
    /// \param min_heap bool whether this should be min heap (true) or max heap (false)
    explicit priority_queue(bool min_heap) : vector<heap_node<T>*>() {
        this->min_heap = min_heap;
    }

    ~priority_queue() {
        while (! vector<heap_node<T>*>::empty()){
            auto* r = vector<heap_node<T>*>::pop_back();
            delete r;
        }
    }

    /// Inserts element in heap
    /// \param value value that has to be inserted
    void insert(T value);

    /// pops element that is on top of heap
    /// \return value of type T
    T pop();

    /// Checks for size of data
    /// \return number of records in container
    int size() {return vector<heap_node<T>*>::size();}

    /// Checks whether heap is empty
    /// \return bool with certain information
    bool empty() {return this->size() == 0;}

    /// Removes every node from tab
    bool clear() {return vector<heap_node<T>*>::clear();}

    /// Function for having data from heap in an array
    /// \return whole array with heap
    heap_node<T>** raw_data() {return vector<heap_node<T>*>::tab_;}

    /// Balances heap from point given - used when element changes in heap and when you insert or pop and element
    /// \param index where to start balancing
    void rebalance(int index) {
        balance_down(vector<heap_node<T>*>::operator[](index));
        balance_up(vector<heap_node<T>*>::operator[](index));
    }

    /// Function for taking top element without having to pop it
    /// \return minimal(min heap)/maximal(max heap) element in heap
    T top(){
        return vector<heap_node<T>*>::operator[](0)->value;
    }

protected:
    /// Swaps elements in heap from 2 indexes
    /// \param f1 index of first element
    /// \param f2 index of second element
    void swap_heap_nodes(int f1, int f2) {
        auto* f1_node = vector<heap_node<T>*>::operator[](f1);
        auto* f2_node = vector<heap_node<T>*>::operator[](f2);
        vector<heap_node<T>*>::replace(f1,f2_node);
        vector<heap_node<T>*>::replace(f2,f1_node);
        f1_node->index = f2;
        f2_node->index = f1;
    }

    /// Balances the heap from index going thru parents
    /// \param node from which should balancing start
    void balance_up(heap_node<T>* node);

    /// Balances the heap from index going thru childs
    /// \param node from which should balancing strart
    void balance_down(heap_node<T>* node);

    /// value in which information on relation is stored (whether it's min heap(true) or max heap(max))
    bool min_heap = true;
};

template<typename T>
void priority_queue<T>::insert(T value) {
    int last_idx = vector<heap_node<T>*>::size();
    vector<heap_node<T>*>::push_back(new heap_node<T>(this,last_idx,value));
    this->rebalance(last_idx);
}

template<typename T>
T priority_queue<T>::pop() {
    if (size() == 1){
        auto ret = vector<heap_node<T>*>::operator[](0)->value;
        auto* s = vector<heap_node<T>*>::pop_back();
        delete s;
        return ret;

    }
    auto ret = vector<heap_node<T>*>::operator[](0)->value;
    swap_heap_nodes(0,size()-1);
    auto* s = vector<heap_node<T>*>::pop_back();
    delete s;
    this->rebalance(0);
    return ret;
}

template<typename T>
void priority_queue<T>::balance_up(heap_node<T>* node){
    if (node->index == 0){
        return;
    }
    auto* parent = vector<heap_node<T>*>::operator[](node->parent());

    if (this->min_heap){
        if (node->value < parent->value){
            swap_heap_nodes(node->index,parent->index);
            balance_up(node);
        }
    }
    else{
        if (node->value > parent->value){
            swap_heap_nodes(node->index,parent->index);
            balance_up(node);
        }
    }
}
template<typename T>
void priority_queue<T>::balance_down(heap_node<T>* node){
    int mini = node->index;
    if (this->min_heap){
        if (node->left() < this->size() && node->value > vector<heap_node<T>*>::operator[](node->left())->value){
            mini = node->left();
        }
        if (node->right() < this->size() && vector<heap_node<T>*>::operator[](mini)->value > vector<heap_node<T>*>::operator[](node->right())->value){
            mini = node->right();
        }
        if(mini != node->index){
            swap_heap_nodes(mini,node->index);
            balance_down(vector<heap_node<T>*>::operator[](mini));
        }
    }

    else{
        if (node->left() < this->size() && node->value < vector<heap_node<T>*>::operator[](node->left())->value){
            mini = node->left();
        }
        if (node->right() < this->size() && vector<heap_node<T>*>::operator[](mini)->value < vector<heap_node<T>*>::operator[](node->right())->value){
            mini = node->right();
        }
        if(mini != node->index){
            swap_heap_nodes(mini,node->index);
            balance_down(vector<heap_node<T>*>::operator[](mini));
        }
    }
}

template<typename T>
T heap_node<T>::change_priority(T new_value) {
    auto ret = this->value;
    this->value = new_value;
    ((priority_queue<T>*) this->pq)->rebalance(this->index);
    return ret;
}



#endif //PRIORITY_QUEUE_HPP
