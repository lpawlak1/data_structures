#include "container.h"

class heap : public linker, public container{
public:
    ~heap();
    heap();
    bool push(int value);
    int pop();
    int peak();
private:
    node* last_;
};