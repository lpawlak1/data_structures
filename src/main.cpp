#include <iostream>
#include "vector.h"

int main(){
    vector a;
    a.push_back(1);
    a.clear();
    if(!a.empty()){
        printf("%d",a.get(0));
    }
    a.insert(0,12);
    a.insert(0,2);
    a.insert(1,123);
    a.insert(1,2);
    printf("%d",a.size());
    
    for(int i = 0; i<a.size();i++){
        printf("> %d, ",a.get(i));
    }
    a.pop(2);
    a.pop_back();
    a.pop_front();
    a.push_back(12);
    a.push_front(22);
    //size() = 3
    printf("%d",a.size());
    a.shrink_to_fit();
    a.shrink(3,1);
    return 0;
}