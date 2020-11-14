#include "stack.h"


templ
stack<T>::stack(){
    size_ = 0;
    last_=nullptr;
}
templ
stack<T>::~stack(){
    node<T>* nod = last_;
    while (size_ > 0){
        nod = last_->previous;
        delete last_;
        size_--;
    }
}
templ
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
templ
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
templ
T stack<T>::peak(){
    return last_->value;
}
templ
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


//troche bruteforce jak na moje ale cóż :/
template class stack<int>;