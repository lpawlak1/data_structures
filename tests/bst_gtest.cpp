//
// Created by lukas on 18.02.2021.
//

#include "bst.hpp"
#include "bst_gtest.h"
#include "gtest/gtest.h"

bst<int>* prepare_bst()
{
    auto* tree = new bst<int>();
    tree->insert(50);
    for(auto i = 0; i < 50; i++){
        tree->insert(i*2);
    }
    return tree;
}
TEST(bst_test, bst_create){
//    auto* tree = new bst<int>();
    auto* tree = new bst<int>();
    tree->insert(50);
    for(auto i = 0; i < 50; i++){
        tree->insert(i*2);
    }
    tree->print();
    delete tree;
}
TEST(bst_test, bst_pop){
    auto* tree = prepare_bst();
    tree->print();
    EXPECT_EQ(0,tree->pop_front());
    EXPECT_EQ(98,tree->pop_back());
    tree->print();
    delete tree;
}
TEST(bst_test, bst_get){
    auto* tree = prepare_bst();
    EXPECT_EQ(20,(*tree)[11]);
    EXPECT_EQ(true,tree->find(50));
    EXPECT_EQ(false,tree->find(37));
    delete tree;
}
TEST(bst_test, bst_clear){
    auto* tree = prepare_bst();
    EXPECT_EQ(true,tree->clear());
    delete tree;
}