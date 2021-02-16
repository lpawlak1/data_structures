#ifndef QUEUE_HPP
#define QUEUE_HPP

#include "container.h"
#include "stdexcept"

//Todo convert queue to one-way linked list
/// basic LIFO structure
template<typename T> class queue : public container{
public:
    /// Puts element on the back of the queue
    /// \param value of type T is put on back
    /// \return bool of success
    bool enqueue(T value);
    /// Removes element from the front
    /// \return T value
    T dequeue();
    /// Peeks at the first element and dont remove it from queue
    /// \return T value
    T peek();
//container
    bool clear() override;
protected:
    /// First element in queue
    node<T>* first_ = nullptr;
    /// Last element in queue
    node<T>* last_ = nullptr;
};

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