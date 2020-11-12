class container{
    public:
        int size() {return size_;};
        bool empty(){return (size_ == 0)? true : false;};
        bool shrink_to_fit();
        bool clear();
    protected:
        container(){};
        int* tab_;
        int container_size_ = 5;
        int initial_size_;
        float load_factor_ = 0.5;
        int size_;
};
class linker{
protected:
    linker(){};
    ~linker(){};
    struct node{
        int value;
        struct node* other = nullptr;
    };
};
