class vector{
    public:
        vector();
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
        int how_add_;
        int last_index_;
        int* tab_;
        int container_size_;
        int* rewrite_append(int a);
        int* rewrite(int size, int first_index);
};