#include "list.h"
#include "array_container.h"
class vector : public list, public array_container{
public:
//own
    vector();
    vector(int initial_size);
    ~vector(){};
//list
    void insert(int index, int value) override;
    int get(int index) override;
    void push_back(int value) override;
    void push_front(int value) override ;
    int pop_front() override;
    int pop_back() override;
    int pop(int index) override;
//container
    bool clear() override;
//array_container
    bool shrink(int size, int first_index) override;
    bool shrink_to_fit() override ;

protected:
//array_contianer
    int* rewrite_append(int value) override;
    int* rewrite(int size, int first_index) override;
};