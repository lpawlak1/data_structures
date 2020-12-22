//
// Created by lukas on 21.12.2020.
//

//TODO link to vector done +
//todo vector to link 
//todo queue to stack
//todo stack to queue
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
//*que is destroyed (is empty)
    que->clear();
    EXPECT_EQ(vec->size(),100);
    EXPECT_EQ((*vec)[0],0);
    EXPECT_EQ((*vec)[12],12);
    vec->clear();
    delete vec;
}