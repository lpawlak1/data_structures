#include "link_vector.h"
//container
templ
bool link_vector<T>::clear()
{
    node<T>* curr = first_;
    while (has_next(curr)){
        curr = curr->next;
        delete curr;
    }
    delete curr;
    size_ = 0;
    first_ = nullptr;
    last_ = nullptr;
    return true;
}
//list
templ
void link_vector<T>::insert(int index, int value)
{
    if (index == 0)
    {
        push_front(value);
    }
    else if (index > size_ || index < 0)
    {
        return; 
    }
    else if (index == size_)
    {
        push_back(value);
    }
    else
    {
        node<T>* new_node = new node<T>();
        new_node->value = value;
        node<T>* curr = find_node(index);
        new_node->next = curr;
        curr->previous = new_node;
        size_++;
    }
}
templ
int link_vector<T>::get(int index)
{
    if(index < 0 || index >= size_)
    {
        return -20;
    }
    return find_node(index)->value;
}
templ
void link_vector<T>::push_front(int value)
{
    if (size_ == 0)
    {
        put_first(value);
        return;
    }
    node<T>* new_node = new node<T>();
    new_node->value = value;
    first_->previous = new_node; 
    new_node->next = first_;
    first_ = new_node;
    size_++;
}
templ
void link_vector<T>::push_back(int value)
{
    if (size_ == 0)
    {
        put_first(value);
        return;
    }
    
    node<T>* new_node = new node<T>();
    new_node->value = value;
    last_->next = new_node; 
    new_node->previous = last_;
    last_ = new_node;
    size_++;
}
templ
int link_vector<T>::pop_front(){
    if (empty())
    {
        return -20;
    }
    else if (size_ == 1)
    {
        return pop_last();
    }
    int ret = first_->value;
    node<T>* for_delete = first_;
    first_->next->previous = nullptr;
    first_ = first_->next;
    delete for_delete;
    size_--;
    return ret;
}
templ
int link_vector<T>::pop_back()
{
    if (empty())
    {
        return -20;
    }
    else if (size_ == 1)
    {
        return pop_last();
    }
    int ret = last_->value;
    node<T>* for_delete = last_;
    last_->previous->next = nullptr;
    last_ = last_->previous;
    delete for_delete;
    size_--; 
    return ret;
}
templ
int link_vector<T>::pop(int index)
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
    int ret = curr->value;
    curr->previous->next = curr->next;
    curr->next->previous = curr->previous;
    delete curr;
    size_--;
    return ret;
}
//own
templ
link_vector<T>::link_vector(){
    size_ =0;
}
templ
link_vector<T>::~link_vector(){
    while (size_ >0){
        node<T>* curr = last_;
        last_ = curr->previous;
        delete curr;
        size_--;
    }
    
}
templ
bool link_vector<T>::has_next(node<T>* curr)
{
    return (curr->next == nullptr)?false:true;
}
templ
bool link_vector<T>::has_previous(node<T>* curr)
{
    return (curr->previous == nullptr)?false:true;
}
templ
void link_vector<T>::put_first(int value)
{
    if (size_ != 0)
    {
        return;
    }
    node<T>* curr = new node<T>();
    curr->value = value;
    first_ = curr;
    last_ = curr;
    size_++;
}
templ
node<T>* link_vector<T>::find_node(int index)
{
    node<T>* curr = nullptr;
    if (size_-index >= index)
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
templ
int link_vector<T>::pop_last()
{
    if (size_ != 1)
    {
        return -20;
    }
    int ret = first_->value;
    delete first_;
    first_ = nullptr;
    last_ = nullptr;
    size_ = 0 ;
    return ret;
}

template class link_vector<int>;