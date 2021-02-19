#ifndef LINK_VECTOR_HPP
#define LINK_VECTOR_HPP

#include "list.hpp"
#include "container.h"
#include "stdexcept"

///It's 2 way linked list.
///Stores: value, next node, previous node
template<typename T> struct node{
    /// Stores value of type T
    T value;
    ///Stores next node
    node* next = nullptr;
    /// Stores previous node
    node* previous = nullptr;
};

/// A class that forms a 2-way linked list using 
/// \link node .
template<typename T> class link_vector : public list<T>, public container
{
public:
//container
/// Deletes every node from memory in O(n)
/// \see container
    bool clear() override;
/// \see list
    void insert(int index,T value) override;
/// \see list
    void push_front(T value) override;
/// \see list
    void push_back(T value) override;
/// \see list
    T pop_front() override;
/// \see list
    T pop_back() override;
/// \see list
    T pop(int index) override;
/// \see list
    T operator[](int index) override;
/// \see list
    void replace(int index, T value) override;
    ///Custom destructor for destroying nodes
    ///It just starts clear()
    ~link_vector();
protected:
    /// Means first node
    node<T>* first_ = nullptr;
    /// Means last node
    node<T>* last_ = nullptr;
private:
    /// Method for returning whether node has next in linked list
    /// \param curr of type node<T>*
    /// \return bool
    bool has_next(node<T>* curr);
    /// Method for returning whether node has previous in linked list
    /// \param curr of type node<T>*
    /// \return bool
    bool has_previous(node<T>* curr);
    /// Method for last index of linked_list
    /// \return integer of last index in link_vector
    int last_index(){return size_-1;};
    /// Insert when linked list is empty
    /// \param value of type T of what to be inserted
    void put_first(T value);
    /// Pop element that is last in linked list, meaning after this there will be no elements in list
    /// \return value of type T
    T pop_last();
    /// Go to certain index and get node that is at this index
    /// \param index int
    /// \return Pointer of type node<T> from index
    node<T>* find_node(int index);
};

//container
template<typename T>
bool link_vector<T>::clear()
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
template<typename T>
void link_vector<T>::insert(int index, T value)
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
template<typename T>
T link_vector<T>::operator[](int index)
{
    if(index < 0 || index >= size_)
    {
        throw std::out_of_range("Index out of range.");
    }
    return find_node(index)->value;
}
template<typename T>
void link_vector<T>::push_front(T value)
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
template<typename T>
void link_vector<T>::push_back(T value)
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
template<typename T>
T link_vector<T>::pop_front(){
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
template<typename T>
T link_vector<T>::pop_back()
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
template<typename T>
T link_vector<T>::pop(int index)
{
    if (index == 0)
    {
        return pop_front();
    }
    else if (index == last_index())
    {
        return pop_back();
    }
    else if (index < 0 || index >= last_index())
    {
        throw std::out_of_range("Index out of range.");
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
template<typename T>
bool link_vector<T>::has_next(node<T>* curr)
{
    return curr->next != nullptr;
}
template<typename T>
bool link_vector<T>::has_previous(node<T>* curr)
{
    return curr->previous != nullptr;
}
template<typename T>
void link_vector<T>::put_first(T value)
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
template<typename T>
node<T>* link_vector<T>::find_node(int index)
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
template<typename T>
T link_vector<T>::pop_last()
{
    T ret = first_->value;
    delete first_;
    first_ = nullptr;
    last_ = nullptr;
    size_ = 0 ;
    return ret;
}

template<typename T>
void link_vector<T>::replace(int index, T value) {
    //if index is invalid throw out_of_range
    if (index > size_ || index < 0)
    {
        throw std::invalid_argument("Index out of range.");
    }
    //if index is in range use find_node and change node from output
    node<T>* nod = find_node(index);
    nod->value = value;
}

template<typename T>
link_vector<T>::~link_vector() {
    this->clear();
}

#endif
