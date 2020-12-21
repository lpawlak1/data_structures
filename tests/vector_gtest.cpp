//
// Created by lukas on 15.12.2020.
//
#include "gtest/gtest.h"
#include "vector.hpp"
#include "vector_gtest.h"

vector<int> prepare_vector(){
    vector<int> vector;
    for(auto i = 0; i < 100; i+=1){
        vector.push_back(i);
    }
    EXPECT_EQ(100,vector.size());
    return vector;
}
TEST(vector_test, push_test){
    vector<int> vector_;
    for(auto i = 0; i < 100; i+=1){
        vector_.push_back(i);
        vector_.push_front(i);
    }
    EXPECT_EQ(200,vector_.size());
}
TEST(vector_test, pop_get_test){
    vector<int> vector_ = prepare_vector();
    EXPECT_EQ(99,vector_[vector_.size()-1]);
    EXPECT_EQ(0,vector_[0]);
    EXPECT_EQ(99,vector_.pop_back());
    EXPECT_EQ(0,vector_.pop_front());
    EXPECT_EQ(1,vector_.pop(0));
    EXPECT_EQ(97,vector_.size());
    vector_.clear();
}
TEST(vector_test, clear_test){
    vector<int> vector_ = prepare_vector();
    vector_.clear();
    EXPECT_TRUE(vector_.empty());
    EXPECT_EQ(0,vector_.size());
}
