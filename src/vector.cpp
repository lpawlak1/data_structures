#include "vector.h"


//* private
int* vector::rewrite_append(int a)
{
    int* ret = new int[container_size_ + how_add_];
    for (int i = 0;i < container_size_;i++){
        ret[i] = tab_[i];
    }
    container_size_ += how_add_;
    ret[last_index_+1] = a;
    last_index_+=1;
    delete [] tab_;
    return ret;
}

int* vector::rewrite(int new_size, int first_index){
    int* ret = new int[new_size];
    int j = 0;
    for (int i = first_index;i < new_size && i <= last_index_;i++){
        ret[j] = tab_[i];
        j+=1;
    }
    container_size_ = new_size;
    last_index_ = j-1;
    delete [] tab_;
    return ret;
}

bool vector::append(int a)
{
    if (container_size_ > last_index_+1)
    {
        tab_[last_index_+1] = a;
        last_index_ += 1;
        return true;
    }
    tab_ = rewrite_append(a);
    return true;
}

//* public
vector::vector(){
    vector::container_size_ = 10;
    tab_ = new int[vector::container_size_];
    vector::how_add_ = 10;
    vector::last_index_ = -1;
}

int vector::size(){
    return last_index_ + 1;
}

int vector::get(int index){
    if (index >=0 && index <= last_index_)
    {
        return tab_[index];
    }
    else{
        return 0;
    }
}

bool vector::push_back(int value){
    return append(value);
}

bool vector::push_front(int value){
    return insert(0,value);
}

bool vector::insert(int index,int value){
    if (index >= 0 && index <= last_index_){
        int i = index;
        int temp = value;
        int temp2 = 0;
        while(i<=last_index_){
            temp2 = tab_[i];
            tab_[i] = temp;
            temp = temp2;
            i+=1;
        }
        append(temp);
    }
    else if (index == 0 && last_index_ == -1){
        append(value);    
    }
    return true;
}

bool vector::pop(int index){
    if (index >= 0 && index < last_index_){
        int i = index;
        while(i<last_index_){
            tab_[i] = tab_[i+1];
            i+=1;
        }
        last_index_--;
    }
    return true;
}

bool vector::pop_back(){
    return pop(last_index_);
}

bool vector::pop_front(){
    return pop(0);
}

bool vector::empty(){
    if (last_index_ == -1)
    {
        return true;
    }
    else{
        return false; 
    }
}

bool vector::shrink(int size, int first_index){
    if (first_index > last_index_)
    {
        return false;
    }
    if(container_size_ > last_index_+1){
        vector::tab_ = vector::rewrite(size,first_index);
        vector::container_size_ = size;
        vector::last_index_ = size-1;
    }
    return 1;
}

bool vector::shrink_to_fit(){
    if (last_index_ + 1 != container_size_)
    {
        return shrink(last_index_+1,0);
    }
    return true;
}

bool vector::clear(){
    delete [] tab_;
    tab_ = new int[how_add_];
    container_size_ = how_add_;
    last_index_ = -1;
    return 1;
}