#include "../src/link_vector.h"
#include <iostream>
int main(){
    link_vector<int> link_vector_;
    printf("start\n");
    for (int i = 0 ;i<1000;i++)
    {
        link_vector_.push_back(100);
    }
    printf("push_back ended\n");

    printf("push_front start\n");
    for (int i = 0 ;i<100;i++)
    {
        link_vector_.push_front(100);
    }
    printf("push_front ended\n");
    printf("%lu",sizeof(link_vector_));

    printf("get start\n");
    link_vector_.get(25);
    link_vector_.get(0);
    link_vector_.get(link_vector_.size()-1);
    link_vector_.get(link_vector_.size()+5);
    link_vector_.get(-100);
    printf("get ended\n");

    printf("pop start\n");
    link_vector_.pop(1);
    link_vector_.pop(-1);
    link_vector_.pop(link_vector_.size()+5);
    printf("pop end\n");

    printf("pop_front/back start\n");
    while (!link_vector_.empty())
    {
        link_vector_.pop_front();
        link_vector_.pop_back();
    }
    printf("pop_front/back end\n");
    printf("done\n");
}