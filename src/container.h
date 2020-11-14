#define templ template<typename T>

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
templ
struct node{
    T value;
    struct node* next = nullptr;
    struct node* previous = nullptr;
};
// class linker{
// protected:
//     linker(){};
//     ~linker(){};
//     struct node{
//         T value;
//         struct node* next = nullptr;
//         struct node* previous = nullptr;
//     };
// };