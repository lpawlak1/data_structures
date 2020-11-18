#include "queue.h"
templ
queue<T>::queue(){
    last_ =nullptr;
    first_ =nullptr;
}
templ
queue<T>::~queue(){
    node<T>* n = first_;
    while(size_ > 0){
       n = first_->next; 
       delete first_;
       size_--;
    }
}
templ
bool queue<T>::enqueue(T value){
    node<T>* n = new node<T>();
    n->value = value;
    size_++;
    if (last_ == nullptr and first_ ==nullptr)
    {
        first_ = n;
        last_ = n;
    }
    else
    {
        last_->next = n;
        last_ = n;
    }
    return true;
}
templ
T queue<T>::dequeue(){
    if (!empty())
    {
        T ret = first_ -> value;
        first_ = first_ -> next;
        size_--;
        return ret;
    }
    else
    {
        throw -2137;
    }
}
templ
T queue<T>::peek(){
    if (!empty())
    {
        return first_->value;
    }
    return -8976756;
}


template class queue<int>;
