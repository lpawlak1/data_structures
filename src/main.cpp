#include <iostream>
#include "vector.h"

int main(){
    vector vec;
    vec.push_back(1);
    vec.clear();
    if(!vec.empty()){
        printf("%d \n",vec.get(0));
    }
    vec.insert(0,12);
    vec.insert(0,2);
    vec.insert(1,123);
    vec.insert(1,2);
    printf("%d \n",vec.size());
    
    for(int i = 0; i<vec.size();i++){
        printf("%d, ",vec.get(i));
    }
    vec.pop(2);
    vec.pop_back();
    vec.pop_front();
    vec.push_back(12);
    vec.push_front(22);
    // * size = 3
    printf("%d",vec.size());
    vec.shrink_to_fit();
    vec.shrink(3,1);
    return 0;
}
