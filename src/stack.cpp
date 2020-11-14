#include "stack.h"

stack::stack(){
    size_ = 0;
    last_=nullptr;
}
stack::~stack(){
    node* nod = last_;
    while (size_ > 0){
        nod = last_->previous;
        delete last_;
        size_--;
    }
}
int stack::pop(){
    if (empty())
    {
        throw -20;
    }
    else
    {
        int ret = last_->value;
        node* nod = last_;
        last_ = last_->previous;
        delete nod;
        size_--;
        return ret;
    }
    return -1; 
}
bool stack::push(int value){
    node* n = new node();
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
int stack::peak(){
    return last_->value;
}