//
// Created by lukasz on 26.11.2020.
//
#include "../src/vector.h"
#include <iostream>

int main(){
    auto* vec = new vector<int>(20,0.8);
    container *a;
    vec -> push_back(1);
    vec -> clear();
    if(vec -> empty()){
        printf(" %d \n",vec -> get(0));
    }
    vec -> insert(0,12);
    vec -> insert(0,2);
    vec -> insert(1,123);
    vec -> insert(1,2);
    printf("%d \n",vec -> size());

    for(int i = 0; i<vec -> size();i++){
        printf("%d, ",vec -> get(i));
    }
    vec -> pop(2);
    vec -> pop_back();
    vec -> pop_front();
    vec -> push_back(12);
    vec -> push_front(22);
    // * size = 3
    a = vec;
    printf("\na - size:%d\n",a->size());
    printf("vec - size:%d\n",vec -> size());
    a->clear();
    printf("po clear ->%d\n",a->size());
    printf("vec - size:%d\n",vec -> size());
    return 0;
}
