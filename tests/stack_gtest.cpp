//
// Created by lukas on 15.12.2020.
//

#include "stack_gtest.h"
#include "stack.h"
#include "gtest/gtest.h"

stack<int> prepare_stack(){
    stack<int> stack;
    auto size = 1000;
    for(auto i = 0;i<size;i++){
        stack.push(i);
    }
    EXPECT_EQ(size,stack.size());
    return stack;
}
TEST(stack_test, push_test){
    stack<int> stack;
    auto size = 1000;
    for(auto i = 0;i<size;i++){
        stack.push(i);
    }
    EXPECT_EQ(size,stack.size());
    stack.clear();
}
TEST(stack_test, peek_pop_test){
    stack<int> stack_ = prepare_stack();
    EXPECT_EQ(999,stack_.pop());
    EXPECT_EQ(998,stack_.peek());
    EXPECT_EQ(998,stack_.pop());
    EXPECT_EQ(998,stack_.size());
    stack_.clear();
}
TEST(stack_test, clear_test){
    auto stack_ = prepare_stack();
    stack_.clear();
    EXPECT_TRUE(stack_.empty());
    EXPECT_EQ(0,stack_.size());
}
