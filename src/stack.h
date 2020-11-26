#include "container.h"
template<typename T> class stack : public container{
public:
    ~stack();
    stack();
    bool push(T value);
    T pop();
    T peek();
    bool clear() override;
private:
    node<T>* last_;
};
template<typename T> stack<T>::stack(){
    size_ = 0;
    last_=nullptr;
}
template<typename T> stack<T>::~stack(){
    node<T>* nod = last_;
    while (size_ > 0)
    {
        node<T>* curr = last_;
        last_ = last_->previous;
        delete curr;
        size_--;
    }
}
template<typename T> T stack<T>::pop(){
    if (empty())
    {
        throw 20;
    }
    else
    {
        T ret = last_->value;
        node<T>* nod = last_;
        last_ = last_->previous;
        delete nod;
        size_--;
        return ret;
    }
}
template<typename T> bool stack<T>::push(T value){
    auto* n = new node<T>();
    n->value = value;
    if (last_ == nullptr)
    {
        last_ = n;
    }
    else
    {
        n->previous = last_;
        last_ = n;
    }
    size_++;
    return true;
}
template<typename T> T stack<T>::peek(){
    return last_->value;
}
template<typename T> bool stack<T>::clear(){
    while (size_ > 0)
    {
        node<T>* curr = last_;
        last_ = last_->previous;
        delete curr;
        size_--;
    }
    return true;
}