#ifndef LIST_HPP
#define LIST_HPP

///Interface for on-list operation with pure virtual methods
/// and protected constructor and destructor
template<typename T> class list
{
public:
    /// Inserts a `value` at a certain `index`
    /// \param index at which value has to be assigned
    /// \param value *self-explanatory*
    virtual void insert(int index, T value) = 0;
    /// Puts a `value` at start of the container
    /// \param value *self-explanatory*
    virtual void push_front(T value) = 0;
    /// Puts a `value` at end of the container
    /// \param value *self-explanatory*
    virtual void push_back(T value) = 0;
    /// Removes value at the beginning of list
    /// \return T value
    virtual T pop_front()  = 0 ;
    /// Removes value at the end of list
    /// \return T value
    virtual T pop_back() = 0;
    /// Removes value from retain index of the list
    /// \param index integer from which spot value will be picked
    /// \return T value
    virtual T pop(int index) = 0;
    /// Picks value from desired index
    /// \param index
    /// \return T value
    virtual T operator[](int index) = 0;
    /// Replacing a value at certain index
    /// \param index  integer for place in list
    /// \param value for what this should be replaced
    virtual void replace(int index, T value) = 0;
protected:
    /// Used to make constructor protected
    list()= default;;
    /// Used to make destructor protected
    ~list()= default;;
};

#endif
