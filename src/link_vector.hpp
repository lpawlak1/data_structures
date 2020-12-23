#ifndef LINK_VECTOR_HPP
#define LINK_VECTOR_HPP

#include "list.hpp"
#include "container.h"
#include "vector.hpp"
#include "stdexcept"

template<typename T> class link_vector : public list<T>, public container
{
public:
    link_vector();
    ~link_vector();
//container
    bool clear() override;
//list
    void insert(int index,T value) override;
    void push_front(T value) override;
    void push_back(T value) override;
    T pop_front() override;
    T pop_back() override;
    T pop(int index) override;
    T operator[](int index) override;
protected:
    node<T>* first_ = nullptr;
    node<T>* last_ = nullptr;
private:
    bool has_next(node<T>* curr);
    bool has_previous(node<T>* curr);
    int last_index(){return size_-1;};
    void put_first(T value);
    T pop_last();
    node<T>* find_node(int index);
};

//container
template<typename T> bool link_vector<T>::clear()
{
    if(size_ == 0){
        return true;
    }
    node<T>* curr = first_;
    node<T>* prev = nullptr;
    while (has_next(curr)){
        curr = curr->next;
        prev = curr-> previous;
        delete prev;
    }
    size_ = 0;
    first_ = nullptr;
    last_ = nullptr;
    return true;
}
//list
template<typename T> void link_vector<T>::insert(int index, T value)
{
    if (index == 0)
    {
        push_front(value);
    }
    else if (index > size_ || index < 0)
    {
        throw std::invalid_argument("Index out of range.");
    }
    else if (index == size_)
    {
        push_back(value);
    }
    else
    {
        auto* new_node = new node<T>();
        new_node->value = value;
        node<T>* curr = find_node(index);
        new_node->next = curr;
        curr->previous = new_node;
        size_++;
    }
}
template<typename T> T link_vector<T>::operator[](int index)
{
    if(index < 0 || index >= size_)
    {
        throw std::out_of_range("Index out of range.");
    }
    return find_node(index)->value;
}
template<typename T> void link_vector<T>::push_front(T value)
{
    if (size_ == 0)
    {
        put_first(value);
        return;
    }
    auto* new_node = new node<T>();
    new_node->value = value;
    first_->previous = new_node;
    new_node->next = first_;
    first_ = new_node;
    size_++;
}
template<typename T> void link_vector<T>::push_back(T value)
{
    if (size_ == 0)
    {
        put_first(value);
        return;
    }

    auto* new_node = new node<T>();
    new_node->value = value;
    last_->next = new_node;
    new_node->previous = last_;
    last_ = new_node;
    size_++;
}
template<typename T> T link_vector<T>::pop_front(){
    if (empty())
    {
        throw std::length_error("Link vector is empty.");
    }
    else if (size_ == 1)
    {
        return pop_last();
    }
    T ret = first_->value;
    node<T>* for_delete = first_;
    first_->next->previous = nullptr;
    first_ = first_->next;
    delete for_delete;
    size_--;
    return ret;
}
template<typename T> T link_vector<T>::pop_back()
{
    if (empty())
    {
        throw std::length_error("Link vector is empty.");
    }
    else if (size_ == 1)
    {
        return pop_last();
    }
    T ret = last_->value;
    node<T>* for_delete = last_;
    last_->previous->next = nullptr;
    last_ = last_->previous;
    delete for_delete;
    size_--;
    return ret;
}
template<typename T> T link_vector<T>::pop(int index)
{
    if (index == 0)
    {
        return pop_front();
    }
    else if (index == last_index())
    {
        return pop_back();
    }
    else if (index < 0 || index > last_index())
    {
        return -20;
    }
    node<T>* curr = find_node(index);
    T ret = curr->value;
    curr->previous->next = curr->next;
    curr->next->previous = curr->previous;
    delete curr;
    size_--;
    return ret;
}
//own
template<typename T> link_vector<T>::link_vector(){
    size_ =0;
}
template<typename T> link_vector<T>::~link_vector(){
    while (size_ >0){
        node<T>* curr = last_;
        last_ = curr->previous;
        delete curr;
        size_--;
    }
}
template<typename T> bool link_vector<T>::has_next(node<T>* curr)
{
    return curr->next != nullptr;
}
template<typename T> bool link_vector<T>::has_previous(node<T>* curr)
{
    return curr->previous != nullptr;
}
template<typename T> void link_vector<T>::put_first(T value)
{
    if (size_ != 0)
    {
        return;
    }
    auto* curr = new node<T>();
    curr->value = value;
    first_ = curr;
    last_ = curr;
    size_++;
}
template<typename T> node<T>* link_vector<T>::find_node(int index)
{
    node<T>* curr = nullptr;
    if (index*2 >= size_)
    {
        curr = last_;
        int i = last_index();
        while (i != index)
        {
            curr = curr->previous;
            i--;
        }
    }
    else
    {
        curr = first_;
        int i = 0;
        while (i != index)
        {
            curr = curr->next;
            i++;
        }
    }
    return curr;
}
template<typename T> T link_vector<T>::pop_last()
{
    T ret = first_->value;
    delete first_;
    first_ = nullptr;
    last_ = nullptr;
    size_ = 0 ;
    return ret;
}

#endif