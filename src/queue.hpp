#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "container.h"

template<typename T> class queue : public container{
public:
    ~queue();
    queue();
    bool enqueue(T value);
    T dequeue();
    T peek();
//container
    bool clear() override;
protected:
    node<T>* first_;
    node<T>* last_;
};

template<typename T> queue<T>::queue(){
    last_ =nullptr;
    first_ =nullptr;
    container::size_ = 0;
}
template<typename T> queue<T>::~queue(){
    node<T>* n = first_;
    while(size_ > 0){
        n = first_->next;
        delete first_;
        size_--;
    }
}
template<typename T> bool queue<T>::enqueue(T value){
    auto* n = new node<T>();
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
template<typename T> T queue<T>::dequeue(){
    if (!empty())
    {
        T ret = first_ -> value;
        auto* d = first_;
        first_ = first_ -> next;
        delete d;
        size_--;
        return ret;
    }
    else
    {
        throw std::length_error("Queue is empty");
    }
}
template<typename T> T queue<T>::peek(){
    if (!empty())
    {
        return first_->value;
    }
    throw std::length_error("Queue is empty");
}

template<typename T> bool queue<T>::clear() {
    while(!empty()){
        dequeue();
    }
    return true;
}

#endif