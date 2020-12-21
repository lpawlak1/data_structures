#ifndef CONTAINER_H
#define CONTAINER_H
class container{
    public:
        int size() const {return size_;};
        bool empty() const{return (size_ == 0);};
        virtual bool clear() = 0;
    protected:
        container()= default;;
        ~container()= default;;
        int size_ = 0;
};
template<typename T> struct node{
    T value;
    struct node* next = nullptr;
    struct node* previous = nullptr;
};

#endif