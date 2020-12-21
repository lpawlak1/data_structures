//
// Created by lukas on 28.11.2020.
//

#include "queue_gtest.h"
#include "queue.hpp"
#include "gtest/gtest.h"
#include "iostream"
queue<int> prepare_queue(){
    queue<int> queue_;
    for(auto i =0;i<100;i++){
        queue_.enqueue(i);
    }
    EXPECT_EQ(100,queue_.size());
    return queue_;
}
TEST(queue_test, enqueue_test){
    queue<int> queue;
    auto size = 1000;
    for(auto i = 0;i<size;i++){
        queue.enqueue(i);
    }
    EXPECT_EQ(size,queue.size());
    queue.clear();
}
TEST(queue_test, peek_dequeue_test){
    queue<int> queue_ = prepare_queue();
    EXPECT_EQ(0,queue_.dequeue());
    EXPECT_EQ(1,queue_.peek());
    EXPECT_EQ(1,queue_.dequeue());
    EXPECT_EQ(98,queue_.size());
    queue_.clear();
}
TEST(queue_test, clear_test){
    auto queue_ = prepare_queue();
    queue_.clear();
    EXPECT_TRUE(queue_.empty());
    EXPECT_EQ(0,queue_.size());
}