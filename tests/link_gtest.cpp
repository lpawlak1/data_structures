//
// Created by lukas on 27.11.2020.
//

#include "gtest/gtest.h"
#include "link_vector.h"

link_vector<int> prepare_link(){
    link_vector<int> linkVector;
    for(auto i = 0; i < 100; i+=1){
        linkVector.push_back(i);
    }
    EXPECT_EQ(100,linkVector.size());
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
    link_vector<int> linkVector = prepare_link();
    EXPECT_EQ(99,linkVector[linkVector.size()-1]);
    EXPECT_EQ(0,linkVector[0]);
    EXPECT_EQ(99,linkVector.pop_back());
    EXPECT_EQ(0,linkVector.pop_front());
    EXPECT_EQ(1,linkVector.pop(0));
    EXPECT_EQ(97,linkVector.size());
}
TEST(link_vector_test, clear_test){
    link_vector<int> linkVector = prepare_link();
    linkVector.clear();
    EXPECT_TRUE(linkVector.empty());
    EXPECT_EQ(0,linkVector.size());
}
