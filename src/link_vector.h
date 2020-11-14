#include "list.h"
#include "container.h"
class link_vector : public list,protected linker, public container
{
public:
    link_vector();
    ~link_vector();
//container
    bool clear() override;
//list
    void insert(int index, int value) override;
    int get(int index) override;
    void push_front(int value) override;
    void push_back(int value) override;
    int pop_front() override;
    int pop_back() override;
    int pop(int index) override;
protected:
    node* first_ = nullptr;
    node* last_ = nullptr;
private:
    bool has_next(node* curr);
    bool has_previous(node* curr);
    int last_index(){return size_-1;};
    void put_first(int value);
    int pop_last();
    node* find_node(int index);
};

