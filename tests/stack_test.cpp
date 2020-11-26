#include "../src/stack.h"
#include <iostream>

int main(){
    auto* st = new stack<int>();
    for (size_t i = 0; i < 1000; i++)
    {
        st->push(i+1);
    }
    for (size_t i = 0; i < 100; i++)
    {
        st->pop();
    }
    printf("%d\n",st->peek());
    printf("%d\n",st->size());
    st->clear();
    if(st->empty()) printf("empty..\n");
}