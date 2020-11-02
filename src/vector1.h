class vector1{
    public:
        vector1();
        bool append(int a);
        int size();
        int get(int index);
        bool push_back(int value);
        bool push_front(int value);
        bool insert(int index, int value);
        bool pop(int index);
        bool pop_back();
        bool pop_front();
        bool empty();
        bool shrink(int size, int first_index);
        bool shrink_to_fit();
        bool clear();
    private:
        int how_add;
        int last_index;
        int* tab;
        int size1;
        int* rewrite_append(int a);
        int* rewrite(int size, int first_index);
};