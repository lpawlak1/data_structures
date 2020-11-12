#include "container.h"

class queue : public linker, public container{
public:
    ~queue();
    queue();
    bool enqueue(int value);
    int dequeue();
    int peek();
    bool is_full(){return size_ == container_size_;};
protected:
    node* first;
    node* last;
};