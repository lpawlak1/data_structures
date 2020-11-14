#include "container.h"
class array_container : public container{
public:
    virtual bool shrink(int size, int first_index);
    virtual bool shrink_to_fit();
protected:
    array_container(){};
    ~array_container(){delete tab_;};
//methods
    virtual int* rewrite_append(int value);
    virtual int* rewrite(int size, int first_index);
//properties
    int* tab_;
    int container_size_ = 5;
    int initial_size_ = 5;
    float load_factor_ = 0.5;
};