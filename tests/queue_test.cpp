//
// Created by lukas on 26.11.2020.
//
#include "../src/queue.h"
#include <iostream>

int main(){
    auto* que = new queue<int>();
    for(auto i = 0; i<1000; i++){
        que -> enqueue(i);
    }
    printf("-> %d\n",que->peek());
    printf("-> %d\n",que->dequeue());
    printf("-> %d\n",que->size());
    que->clear();
    if(que->empty()){
        printf("is empty\n");
    }
    delete que;
    return 0;
}
