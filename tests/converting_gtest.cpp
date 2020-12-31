//
// Created by lukas on 21.12.2020.
//

#include "gtest/gtest.h"
#include "converting_gtest.h"
#include "convert_structure.hpp"


TEST(convert_test_vector, link_vector){
    auto* linkVector = new link_vector<int>();
    for(auto i = 0; i < 100; i+=1){
        linkVector->push_back(i);
    }
    EXPECT_EQ(100,linkVector->size());
    EXPECT_EQ((*linkVector)[12],12);
    vector<int>* vec;
    vec =  convert_structure::convert_to_vector(linkVector);
    EXPECT_EQ(vec->size(),linkVector->size());
    EXPECT_EQ((*vec)[12],(*linkVector)[12]);
    EXPECT_EQ((*vec)[54],(*linkVector)[54]);
    vec->clear();
    linkVector->clear();
    delete vec;
    delete linkVector;
}
TEST(convert_test_vector, queue){
    auto* que = new queue<int>();
    for(auto i = 0; i < 100; i+=1){
        que->enqueue(i);
    }
    EXPECT_EQ(100,que->size());
    vector<int>* vec;
    vec =  convert_structure::convert_to_vector(que);
//!que is destroyed (is empty)
    que->clear();
    EXPECT_EQ(vec->size(),100);
    EXPECT_EQ((*vec)[0],0);
    EXPECT_EQ((*vec)[12],12);
    vec->clear();
    delete vec;
}
TEST(convert_test_vector, stack)
{
    auto* au = new stack<int>();
    for(auto i = 0;i <100; i++){
        au->push(i);
    }
    EXPECT_EQ(100,au->size());
    vector<int>* vec;
    vec = convert_structure::convert_to_vector(au);
//!stack is destroyed(is empty)
    EXPECT_EQ(vec->size(),100);
    EXPECT_EQ((*vec)[0],0);
    EXPECT_EQ((*vec)[12],12);
    vec->clear();
    delete vec;
}
TEST(convert_test_link, vector)
{
    auto* vec = new vector<int>();
    for(auto i = 0; i < 100; i+=1){
        vec->push_back(i);
    }
    EXPECT_EQ(100,vec->size());
    EXPECT_EQ((*vec)[12],12);
    link_vector<int>* linkVector;
    linkVector =  convert_structure::convert_to_link_vector(vec);
    EXPECT_EQ(vec->size(),linkVector->size());
    EXPECT_EQ((*vec)[12],(*linkVector)[12]);
    EXPECT_EQ((*vec)[54],(*linkVector)[54]);
    linkVector->clear();
    delete vec;
    delete linkVector;
}
TEST(convert_test_link, queue){
    auto* que = new queue<int>();
    for(auto i = 0; i < 100; i+=1){
        que->enqueue(i);
    }
    EXPECT_EQ(100,que->size());
    link_vector<int>* link;
    link =  convert_structure::convert_to_link_vector(que);
//!que is destroyed (is empty)
    que->clear();
    EXPECT_EQ(link->size(),100);
    EXPECT_EQ((*link)[0],0);
    EXPECT_EQ((*link)[12],12);
    link->clear();
    delete link;
}
TEST(convert_test_link, stack)
{
    auto* au = new stack<int>();
    for(auto i = 0;i <100; i++){
        au->push(i);
    }
    EXPECT_EQ(100,au->size());
    link_vector<int>* link;
    link = convert_structure::convert_to_link_vector(au);
//!stack is destroyed(is empty)
    EXPECT_EQ(link->size(),100);
    EXPECT_EQ((*link)[0],0);
    EXPECT_EQ((*link)[12],12);
    link->clear();
    delete link;
}
