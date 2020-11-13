#include "container.h"

class queue : public linker, public container{
public:
    ~queue();
    queue();
    bool enqueue(int value);
    int dequeue();
    int peek();
//container
    bool clear() override;
protected:
    node* first_;
    node* last_;
};