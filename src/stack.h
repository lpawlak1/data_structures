#include "container.h"
template<typename T>
class stack : public container{
public:
    ~stack();
    stack();
    bool push(T value);
    T pop();
    T peak();
    bool clear() override;
private:
    node<T>* last_;
};