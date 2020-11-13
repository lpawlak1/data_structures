class list 
{
public:
    list();
    ~list();
    virtual void insert(int index, int value) = 0;
    virtual int get(int index) = 0;
    virtual void push_front(int value) = 0;
    virtual void push_back(int value) = 0;
    virtual int pop_front()  = 0 ;
    virtual int pop_back() = 0;
    virtual int pop(int index) = 0;
};