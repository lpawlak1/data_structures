//
// Created by lukas on 11.05.2021.
//

#include "avl_gtest.h"
#include "avl_tree.hpp"
#include "gtest/gtest.h"

avl_tree<int>* prepare_avl_tree()
{
    auto* tree = new avl_tree<int>();
    tree->insert(50);
    for(auto i = 0; i < 50; i++){
        tree->insert(i*2);
    }
    return tree;
}
TEST(avl_test, avl_create){
    auto* tree = new avl_tree<int>();
    tree->insert(50);
    for(auto i = 0; i < 50; i++){
        tree->insert(i*2);
        tree->print();
    }
    delete tree;
}
TEST(avl_tree_test, avl_tree_pop){
    auto* tree = prepare_avl_tree();
    tree->print();
    EXPECT_EQ(0,tree->pop_front());
    EXPECT_EQ(98,tree->pop_back());
    tree->print();
    delete tree;
}
TEST(avl_tree_test, avl_tree_get){
    auto* tree = prepare_avl_tree();
    EXPECT_EQ(20,(*tree)[11]);
    EXPECT_EQ(true,tree->find(50));
    EXPECT_EQ(false,tree->find(37));
    delete tree;
}
TEST(avl_tree_test, avl_tree_clear){
    auto* tree = prepare_avl_tree();
    EXPECT_EQ(true,tree->clear());
    delete tree;
}
