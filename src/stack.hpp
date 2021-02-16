#ifndef STACK_HPP
#define STACK_HPP

#include "container.h"
#include "stdexcept"

//Todo convert stack to one-way linked list
/// Basic FIFO structure
template<typename T> class stack : public container{
public:
    /// Pushes value on top of the stack
    /// \param value of type T to be pushed on top
    /// \return bool of success
    bool push(T value);
    /// Pops the top value from the stack
    /// \return T value
    T pop();
    /// Peeks the top value from the stack
    /// \return T value of the top value
    T peek();
//container
    bool clear() override;
private:
    /// contains top node of the stack
    node<T>* last_ = nullptr;
};

template<typename T>
T stack<T>::pop(){
    if (empty())
    {
        throw std::length_error("Stack is empty");
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
}
template<typename T>
bool stack<T>::push(T value){
    auto* n = new node<T>();
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
T stack<T>::peek(){
    if (empty())
    {
        throw std::length_error("Stack is empty");
    }
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

#endif