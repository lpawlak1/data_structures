
#ifndef BST_HPP
#define BST_HPP
#include "sorted_list.hpp"
#include "container.h"
#include "stdexcept"
#include <exception>

///Tree leave
template<typename T> struct leave{
    /// Stores value of type T
    T value;
    /// Stores right leave
    leave* right = nullptr;
    /// Stores left leave
    leave* left = nullptr;
};


///Binary Search Tree with list interface
///It's using Node-like objects
template<typename T> class bst : public sorted_list<T>, public container {
public:
//sorted_list
    void insert(T value) override;
    T pop_front() override;
    T pop_back() override;
    T pop(int index) override;
    T operator[](int index) override;
    bool find(T value) override;
private:
    leave<T>* find_parent(T value);
    leave<T>* find_leave(T value);
    leave<T>* head = nullptr;
    void insert_rec(leave<T>* head,T value);
};
template<typename T>
void bst<T>::insert(T value)
{
    if(head == nullptr){
        head = new leave<T>();
        head->value = value;
        container::size_=1;
    }
    else{
        insert_rec(head,value);
        container::size_ ++;
    }
}
template<typename T>
void insert_rec(leave<T>* head, T value){
    if (value > head->value){
        if (head->right == nullptr){
            head->right = new leave<T>();
            head->right->value = value;
        }
        insert_rec(head->right, value);
    }
    else if (value < head->value){
        if (head->left== nullptr){
            head->left = new leave<T>();
            head->left->value = value;
        }
        insert_rec(head->left, value);
    }
}
#endif













