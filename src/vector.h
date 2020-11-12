#include "container.h"
class vector : public container{
    public:
        vector();
        vector(int initial_size);
        int get(int index);
        bool push_back(int value);
        bool push_front(int value);
        bool insert(int index, int value);
        bool pop(int index);
        bool pop_back();
        bool pop_front();
        bool shrink(int size, int first_index);
        bool shrink_to_fit();
        bool clear();
    private:
        bool append(int value);
        int* rewrite_append(int value);
        int* rewrite(int size, int first_index);
        
};