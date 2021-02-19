#ifndef STACK_HPP
#define STACK_HPP

#include "container.h"
#include "stdexcept"

/// Used only in stack as a (one) element container
template<typename T>
struct stack_node{
    T value;
    stack_node<T>* previous = nullptr;
};

/// Basic FIFO structure
///Uses stack_node (one way node)
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
    ///Destructor for removing all nodes from memory
    ~stack();
    /// Pops every element in stack 
    /// \see container
    bool clear() override;
private:
    /// contains top node of the stack
    stack_node<T>* last_ = nullptr;
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
        stack_node<T>* nod = last_;
        last_ = last_->previous;
        delete nod;
        size_--;
        return ret;
    }
}
template<typename T>
bool stack<T>::push(T value){
    auto* n = new stack_node<T>();
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
        stack_node<T>* curr = last_;
        last_ = last_->previous;
        delete curr;
        size_--;
    }
    return true;
}

template<typename T>
stack<T>::~stack() {
    this->clear();
}

#endif
