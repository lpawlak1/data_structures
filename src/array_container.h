#include "container.h"

template<typename T> class array_container : public container{
protected:
    array_container();
    array_container(int initial_size);
    array_container(int initial_size,float load_factor);
    array_container(float load_factor);
    ~array_container(){delete tab_;};
//methods
    virtual T* rewrite_append(T value) = 0;
    virtual T* rewrite(int size, int first_index) = 0;
//properties
    T* tab_ = nullptr;
    int container_size_;
    int initial_size_;
    float load_factor_;
};

template<typename T> array_container<T>::array_container() : array_container<T>::array_container(5,0.5){}
template<typename T> array_container<T>::array_container(int initial_size) : array_container<T>::array_container(initial_size,0.5){}
template<typename T> array_container<T>::array_container(float load_factor): array_container<T>::array_container(5,load_factor){}
template<typename T> array_container<T>::array_container(int initial_size,float load_factor) {
    tab_ = new T[initial_size];
    this -> initial_size_ = initial_size;
    this -> container_size_ = initial_size;
    this -> load_factor_ = load_factor;
    this -> container::size_ = 0;
}