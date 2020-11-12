#include "container.h"
class list : public container, public linker
{
private:

    /* data */
public:
    list(/* args */);
    ~list();
    virtual void insert();
    virtual int get(int index);
    virtual void push_front();
    virtual void push_back();
    virtual void pop_front();
    virtual void pop_back();
    virtual void pop();
protected:
    node* first = nullptr;
    node* last = nullptr;

};