#include "queue.h"
queue::queue(){
    last_ =nullptr;
    first_ =nullptr;
}
queue::~queue(){
    node* n = first_;
    while(size_ > 0){
       n = first_->next; 
       delete first_;
       size_--;
    }
}
bool queue::enqueue(int value){
    node* n = new node();
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
int queue::dequeue(){
    if (!empty())
    {
        int ret = first_ -> value;
        first_ = first_ -> next;
        size_--;
        return ret;
    }
    else
    {
        throw -2137;
    }
}
int queue::peek(){
    if (!empty())
    {
        return first_->value;
    }
    return -8976756;
}