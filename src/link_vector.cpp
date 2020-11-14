#include "link_vector.h"
//container
bool link_vector::clear()
{
    node* curr = first_;
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
void link_vector::insert(int index, int value)
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
        node* new_node = new node();
        new_node->value = value;
        node* curr = find_node(index);
        new_node->next = curr;
        curr->previous = new_node;
        size_++;
    }
}
int link_vector::get(int index)
{
    if(index < 0 || index >= size_)
    {
        return -20;
    }
    return find_node(index)->value;
}
void link_vector::push_front(int value)
{
    if (size_ == 0)
    {
        put_first(value);
        return;
    }
    node* new_node = new node();
    new_node->value = value;
    first_->previous = new_node; 
    new_node->next = first_;
    first_ = new_node;
    size_++;
}
void link_vector::push_back(int value)
{
    if (size_ == 0)
    {
        put_first(value);
        return;
    }
    
    node* new_node = new node();
    new_node->value = value;
    last_->next = new_node; 
    new_node->previous = last_;
    last_ = new_node;
    size_++;
}
int link_vector::pop_front(){
    if (empty())
    {
        return -20;
    }
    else if (size_ == 1)
    {
        return pop_last();
    }
    int ret = first_->value;
    node* for_delete = first_;
    first_->next->previous = nullptr;
    first_ = first_->next;
    delete for_delete;
    size_--;
    return ret;
}
int link_vector::pop_back()
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
    node* for_delete = last_;
    last_->previous->next = nullptr;
    last_ = last_->previous;
    delete for_delete;
    size_--; 
    return ret;
}
int link_vector::pop(int index)
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
    node* curr = find_node(index);
    int ret = curr->value;
    curr->previous->next = curr->next;
    curr->next->previous = curr->previous;
    delete curr;
    size_--;
    return ret;
}
//own
link_vector::link_vector(){
    size_ =0;
}
link_vector::~link_vector(){
    while (size_ >0){
        node* curr = last_;
        last_ = curr->previous;
        delete curr;
        size_--;
    }
    
}
bool link_vector::has_next(node* curr)
{
    return (curr->next == nullptr)?false:true;
}
bool link_vector::has_previous(node* curr)
{
    return (curr->previous == nullptr)?false:true;
}
void link_vector::put_first(int value)
{
    if (size_ != 0)
    {
        return;
    }
    node* curr = new node();
    curr->value = value;
    first_ = curr;
    last_ = curr;
    size_++;
}
linker::node* link_vector::find_node(int index)
{
    node* curr = nullptr;
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
int link_vector::pop_last()
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