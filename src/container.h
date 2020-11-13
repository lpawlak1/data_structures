class container{
    public:
        int size() {return size_;};
        bool empty(){return (size_ == 0)? true : false;};
        virtual bool clear() = 0;
    protected:
        container(){};
        ~container(){};
        int size_;
};
class linker{
protected:
    linker(){};
    ~linker(){};
    struct node{
        int value;
        struct node* next = nullptr;
        struct node* previous = nullptr;
    };
};