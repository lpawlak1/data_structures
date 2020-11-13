#include "container.h"

class stack : public linker, public container{
public:
    ~stack();
    stack();
    bool push(int value);
    int pop();
    int peak();
    bool clear() override;
private:
    node* last_;
};