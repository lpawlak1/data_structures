#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "list.hpp"
#include "array_container.hpp"
#include "stdexcept"

///Resizeable array
template<typename T> class vector : public list<T>, public array_container<T>{
public:
//own
    /// Default constructor
    vector();
    /// Constructor with possibility
    /// \param initial_size for container
    vector(int initial_size);
//list
    void insert(int index, T value) override;
    void push_back(T value) override;
    void push_front(T value) override ;
    T pop_front() override;
    T pop_back() override;
    T pop(int index) override;
    T operator[](int index) override;
    void replace(int index, T value) override;
};


//* public
template<typename T> vector<T>::vector() : array_container<T>::array_container(){
}
template<typename T> vector<T>::vector(int initial_size) : array_container<T>::array_container(initial_size){}

template<typename T>
T vector<T>::operator[](int index) {
    if (index >=0 && index < container::size_){
        return array_container<T>::tab_[index];
    }
    else{
        throw std::out_of_range("Index out of range.");
    }
}
template<typename T>
void vector<T>::push_back(T value){
    if (array_container<T>::container_size_ > container::size_)
    {
        array_container<T>::tab_[container::size_] = value;
        container::size_ += 1;
        return;
    }
    array_container<T>::tab_ = array_container<T>::rewrite_append(value);
}
template<typename T>
void vector<T>::push_front(T value){
    return insert(0,value);
}
template<typename T>
void vector<T>::insert(int index,T value){
    if (index >= 0 && index < container::size_){
        int i = index;
        T temp = value;
        T temp2;
        while(i<container::size_){
            temp2 = array_container<T>::tab_[i];
            array_container<T>::tab_[i] = temp;
            temp = temp2;
            i+=1;
        }
        push_back(temp);
    }
    else if (index == container::size_){
	    push_back(value);
    }
    else{
        throw std::out_of_range("Index out of range.");
    }
}

template<typename T>
T vector<T>::pop(int index){
    if (index >= 0 && index < container::size_){
        auto ret = array_container<T>::tab_[index];
        int i = index;
        while(i<container::size_-1){
            array_container<T>::tab_[i] = array_container<T>::tab_[i+1];
            i+=1;
        }
        container::size_--;
        if (container::size_ != 0 && array_container<T>::container_size_ / container::size_ < 0.25){
            this->rewrite(array_container<T>::container_size_/0.25,0);
        }
        return ret;
    }
    else
    {
        throw std::out_of_range("Index out of range.");
    }
}
template<typename T>
T vector<T>::pop_back(){
    return pop(container::size_-1);
}
template<typename T>
T vector<T>::pop_front(){
    return pop(0);
}
template<typename T>
void vector<T>::replace(int index, T value) {
    //if index is invalid throw out_of_range
    if (index > container::size_ || index < 0)
    {
        throw std::invalid_argument("Index out of range.");
    }
    //if index is in range change value in tab_ from array_container
    array_container<T>::tab_[index] = value;
}

#endif
