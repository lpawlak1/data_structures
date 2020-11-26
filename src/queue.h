#include "container.h"

template<typename T>
class queue : public container{
public:
    ~queue();
    queue();
    bool enqueue(T value);
    T dequeue();
    T peek();
//container
    bool clear() override;
protected:
    node<T>* first_;
    node<T>* last_;
};


