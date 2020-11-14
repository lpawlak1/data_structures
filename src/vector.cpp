#include "vector.h"

//* private
int* vector::rewrite_append(int a)
{
    int* tab =  this -> rewrite(container_size_*2,0);
    this -> push_back(a);
    return tab;
}

int* vector::rewrite(int new_size, int first_index){
    int* ret = new int[new_size];
    int j = 0;
    for (int i = first_index;i < new_size && i < size_;i++){
        ret[j] = tab_[i];
        j+=1;
    }
    container_size_ = new_size;
    size_ = j;
    delete [] tab_;
    return ret;
}


//* public
vector::vector(){
    container_size_ = 10;
    tab_ = new int[container_size_];
    size_ = 0;
}

int vector::get(int index){
    if (index >=0 && index <= size_){
        return tab_[index];
    }
    else{
        throw 123;
    }
}

void vector::push_back(int value){
    //todo load factor
    if (container_size_ > size_)
    {
        tab_[size_] = value;
        size_ += 1;
        return; 
    }
    tab_ = rewrite_append(value);
}

void vector::push_front(int value){
    return insert(0,value);
}

void vector::insert(int index,int value){
    if (index >= 0 && index < size_){
        int i = index;
        int temp = value;
        int temp2 = 0;
        while(i<size_){
            temp2 = tab_[i];
            tab_[i] = temp;
            temp = temp2;
            i+=1;
        }
        push_back(temp);
    }
    else if (index == 0 && size_ == 0){
        push_back(value);
    }
}

int vector::pop(int index){
    if (index >= 0 && index < size_){
        int i = index;
        while(i<size_-1){
            tab_[i] = tab_[i+1];
            i+=1;
        }
        size_--;
    }
    return true;
}

int vector::pop_back(){
    return pop(size_-1);
}

int vector::pop_front(){
    return pop(0);
}

bool vector::shrink(int size, int first_index){
    if (first_index >= size_)
    {
        return false;
    }
    if(container_size_ > size_){
        tab_ = vector::rewrite(size,first_index);
        container_size_ = size;
        size_ = size;
    }
    return 1;
}

bool vector::shrink_to_fit(){
    if (size_==0)
    {
        delete [] tab_;
        tab_ = new int[initial_size_];
    }
    if (size_ != container_size_)
    {
        return this->shrink(size_,0);
    }
    return true;
}

bool vector::clear(){
    delete [] tab_;
    tab_ = new int[initial_size_];
    size_ = 0;
    return 1;
}