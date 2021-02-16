#ifndef CONTAINER_H
#define CONTAINER_H
///Interface used in all structures
class container{
    public:
        /// Method to show how much data it holds
        /// \return integer of size
        int size() const {return size_;};

        /// Check if container is empty
        /// \return bool meaning what the state is
        bool empty() const{return (size_ == 0);};

        /// Used to delete every element in container, is pure-virtual and implemented in child classes
        /// \return bool of success
        virtual bool clear() = 0;

    protected:
        ///Constructor in protected, only for child classes
        container()= default;;
        ///Destructor in protected, only for child classes
        ~container()= default;;
        /// stores how many elements are in container
        int size_ = 0;
};
///2 way linked list
///stores value, next node ,previous node
template<typename T> struct node{
    /// Stores value of type T
    T value;
    ///Stores next node
    node* next = nullptr;
    /// Stores previous node
    node* previous = nullptr;
};

#endif