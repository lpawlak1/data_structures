#ifndef sorted_list_hpp
#define sorted_list_hpp
/// Only reliable on sorted structures. 
/// Interface for on-list operation with pure virtual methods
/// and protected constructor and destructor.


template<typename T> class sorted_list
{
public:
    /// Insert a `value` at its spot
    /// \param value *self-explanatory*
    virtual void insert(T value)=0;
    /// Removes value at the beginning of list
    /// \return T value
    virtual T pop_front()  = 0 ;
    /// Removes value at the end of list
    /// \return T value
    virtual T pop_back() = 0;
    /// Picks value from desired index
    /// \param index
    /// \return T value
    virtual T operator[](int index) = 0;
    /// Check if value is in list
    /// \param value of type T for search
    /// \return bool true if element is in list
    virtual bool find(T value) = 0;
protected:
    /// Used to make constructor protected
    sorted_list()=default;;
    /// Used to make destructor protected
    ~sorted_list()=default;;
};
#endif

