#include "../src/stack.h"
#include <iostream>

int main(){
    stack<int>* st = new stack<int>();
    for (size_t i = 0; i < 1000; i++)
    {
        st->push(123);
    }
    for (size_t i = 0; i < 100; i++)
    {
        st->pop();
    }
    printf("%d\n",st->size());
    st->clear();
    if(st->empty()) printf("empty..\n");
}

