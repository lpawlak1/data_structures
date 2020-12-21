#ifndef LIST_HPP
#define LIST_HPP

template<typename T> class list
{
public:
    virtual void insert(int index, T value) = 0;
    virtual void push_front(T value) = 0;
    virtual void push_back(T value) = 0;
    virtual T pop_front()  = 0 ;
    virtual T pop_back() = 0;
    virtual T pop(int index) = 0;
    virtual T operator[](int index) = 0;
protected:
    list(){};
    ~list(){};
};

#endif