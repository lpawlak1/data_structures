//
// Created by lukas on 27.11.2020.
//

#include "gtest/gtest.h"
#include "link_vector.hpp"

link_vector<int>* prepare_link(){
    link_vector<int>* linkVector = new link_vector<int>();
    for(auto i = 0; i < 100; i+=1){
        linkVector->push_back(i);
    }
    EXPECT_EQ(100,linkVector->size());
    return linkVector;
}

TEST(link_vector_test, push_test){
    link_vector<int> linkVector;
    for(auto i = 0; i < 100; i+=1){
        linkVector.push_back(i);
        linkVector.push_front(i);
    }
    EXPECT_EQ(200,linkVector.size());
}
TEST(link_vector_test, pop_get_test){
    link_vector<int>* linkVector = prepare_link();
    EXPECT_EQ(99,(*linkVector)[99]);
    EXPECT_EQ(0,(*linkVector)[0]);
    EXPECT_EQ(12,(*linkVector)[12]);
    EXPECT_EQ(80,(*linkVector)[80]);
    EXPECT_EQ(99,linkVector->pop_back());
    EXPECT_EQ(0,linkVector->pop_front());
    EXPECT_EQ(1,linkVector->pop(0));
    EXPECT_EQ(97,linkVector->size());
    EXPECT_THROW((*linkVector)[-1],std::out_of_range);
    EXPECT_THROW((*linkVector)[10000],std::out_of_range);
    linkVector->replace(0,123);
    EXPECT_EQ(123,(*linkVector)[0]);
    EXPECT_THROW(linkVector->replace(10000,123),std::invalid_argument);
    while(!(*linkVector).empty())
    {
        linkVector->pop_front();
    }
    EXPECT_THROW(linkVector->pop_front(),std::length_error);
    EXPECT_THROW(linkVector->pop_back(),std::length_error);
}
TEST(link_vector_test, clear_test){
    link_vector<int>* linkVector = prepare_link();
    linkVector->clear();
    EXPECT_TRUE(linkVector->empty());
    EXPECT_EQ(0,linkVector->size());
}
