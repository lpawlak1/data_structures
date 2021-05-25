//container.h
#ifndef ARRAY_CONTAINER_HPP
#define ARRAY_CONTAINER_HPP

#include "container.h"

///default initial size for array
#define DEF_INIT_SIZE 6

///Interface for structures which uses arrays as base.
template<typename T> class array_container : public container{

public:
    /// Method from 'container' class that deletes every item in container
    /// \return success as true and false otherwise
    bool clear() override;

//all methods are protected as they are only used in child classes
protected:
    /// Used to make constructor protected
    array_container();
    /// Used to make destructor protected
    explicit array_container(int initial_size);

    ~array_container();



    /// Method used for rewriting data to a new array and appending `value` at the end od array
    /// \param value of type T as what to append to array after rewriting
    T* rewrite_append(T value);
    /// Method used for rewriting into a new `size` starting from a `first_index`
    /// \param size new size of the container
    /// \param first_index from which index to start rewriting
    /// \return A pointer to a new array
    T* rewrite(int size, int first_index);


///actual array containing data
    T* tab_ = nullptr;

///current array size
    int container_size_{};

///initial size for array, used for clear method ,from container, as its the initial size after clearing
    int initial_size_{};

};


template<typename T>
T* array_container<T>::rewrite_append(T value)
{
    int* tab =  this -> rewrite(array_container<T>::container_size_*2,0);
    tab[container::size_] = value;
    container::size_++;
    return tab;
}

template<typename T>
T* array_container<T>::rewrite(int new_size, int first_index){
    int* ret = new int[new_size];
    int j = 0;
    for (int i = first_index;i < new_size && i < container::size_;i++){
        ret[j] = array_container<T>::tab_[i];
        j+=1;
    }
    array_container<T>::container_size_ = new_size;
    container::size_ = j;
    delete[] array_container<T>::tab_;
    return ret;
}
template<typename T>
bool array_container<T>::clear(){
    delete [] array_container<T>::tab_;
    array_container<T>::tab_ = new T[array_container<T>::initial_size_];
    container::size_ = 0;
    return true;
}

template<typename T>
array_container<T>::array_container() {
    this->initial_size_ = DEF_INIT_SIZE;
    this->tab_ = new int[initial_size_];
    this->container_size_ = initial_size_;
}

template<typename T>
array_container<T>::array_container(int initial_size) {
    this->initial_size_ = initial_size;
    this->tab_ = new int[initial_size_];
    this->container_size_ = initial_size_;
}

template<typename T>
array_container<T>::~array_container() {
    delete[] tab_;
}

#endif
