#include "stack.h"


template<typename T>
stack<T>::stack(){
    size_ = 0;
    last_=nullptr;
}
template<typename T>
stack<T>::~stack(){
    node<T>* nod = last_;
    while (size_ > 0){
        nod = last_->previous;
        delete last_;
        size_--;
    }
}
template<typename T>
T stack<T>::pop(){
    if (empty())
    {
        throw -20;
    }
    else
    {
        T ret = last_->value;
        node<T>* nod = last_;
        last_ = last_->previous;
        delete nod;
        size_--;
        return ret;
    }
    return -1; 
}
template<typename T>
bool stack<T>::push(T value){
    node<T>* n = new node<T>();
    n->value = value;
    if (last_ == nullptr)
    {
        last_ = n;
    }
    else
    {
        n->previous = last_;
        last_ = n;
    }
    size_++;
    return true;
}
template<typename T>
T stack<T>::peak(){
    return last_->value;
}
template<typename T>
bool stack<T>::clear(){
    while (size_ > 0)
    {
        node<T>* curr = last_;
        last_ = last_->previous;
        delete curr;
        size_--;
    }
    return true;
}


template class stack<int>;