//
// Created by lukas on 15.12.2020.
//
#include "gtest/gtest.h"
#include "vector.h"

vector<int> prepare_vector(){
    vector<int> vector;
    for(auto i = 0; i < 100; i+=1){
        vector.push_back(i);
    }
    EXPECT_EQ(100,vector.size());
    return vector;
}

TEST(vector_test, push_test){
    vector<int> vector;
    for(auto i = 0; i < 100; i+=1){
        vector.push_back(i);
        vector.push_front(i);
    }
    EXPECT_EQ(200,vector.size());
}
TEST(vector_test, pop_get_test){
    vector<int> vector = prepare_vector();
    EXPECT_EQ(99,vector[vector.size()-1]);
    EXPECT_EQ(0,vector[0]);
    EXPECT_EQ(99,vector.pop_back());
    EXPECT_EQ(0,vector.pop_front());
    EXPECT_EQ(1,vector.pop(0));
    EXPECT_EQ(97,vector.size());
}
TEST(vector_test, clear_test){
    vector<int> vector = prepare_vector();
    vector.clear();
    EXPECT_TRUE(vector.empty());
    EXPECT_EQ(0,vector.size());
}
