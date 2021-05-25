//
// Created by lukas on 11.05.2021.
//

#include "avl_gtest.h"
#include "avl_tree.hpp"
#include "gtest/gtest.h"



bool dfs(leaf<int>* leaf){
    if (leaf == nullptr){
        return true;
    }
    bool retur = true;
    if (leaf->left != nullptr){
        if (leaf->left->parent != leaf){
            std::cout << leaf->left->value << ", " << leaf->value << std::endl;
            return false;
        }

        retur &= dfs(leaf->left);
    }
    if (leaf->right != nullptr){
        if (leaf->right->parent != leaf) {
            std::cout << leaf->left->value << ", " << leaf->value << std::endl;
            return false;
        }
        retur &= dfs(leaf->right);
    }
    return retur;
}

bool checkIntegrity(avl_tree<int>* tree){
    auto* head = (leaf<int>*) tree->get_data_avl();
    if (head == nullptr){
        return true;
    }
    bool ret = true;
    if (head->left != nullptr)
        ret &= dfs(head->left);
    if (head->right != nullptr)
        ret &= dfs(head->right);
    ret &= (head->parent == nullptr);
    return ret;
}

avl_tree<int>* prepare_avl_tree()
{
    auto* tree = new avl_tree<int>();
    tree->insert(50);
    for(auto i = 0; i < 50; i++){
        tree->insert(i*2);
    }
    return tree;
}
TEST(avl_tree_test, avl_create){
    auto* tree = new avl_tree<int>();
    tree->insert(50);
    for(auto i = 0; i < 50; i++){
        tree->insert(i*2);
        EXPECT_EQ(true,checkIntegrity(tree));
    }
    EXPECT_EQ(true,checkIntegrity(tree));
    tree->print();
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
    for( int i = 0; i < 50; i+=2) {
        EXPECT_EQ(true, tree->find(i));
        EXPECT_EQ(false, tree->find(i+1));
    }
    delete tree;
}
TEST(avl_tree_test, avl_tree_clear){
    auto* tree = prepare_avl_tree();
    EXPECT_EQ(true,tree->clear());
    delete tree;
}
TEST(avl_tree_test, avl_tree_remove){
    auto* tree = prepare_avl_tree();
    tree->print();

    EXPECT_EQ(true,tree->remove_by_key(42));
    EXPECT_EQ(false,tree->remove_by_key(42));

    EXPECT_EQ(true,tree->remove_by_key(32));
    EXPECT_EQ(false,tree->remove_by_key(32));

    EXPECT_EQ(true,tree->remove_by_key(72));
    EXPECT_EQ(false,tree->remove_by_key(72));


    EXPECT_EQ(true,tree->remove_by_key(12));
    EXPECT_EQ(false,tree->remove_by_key(12));

    EXPECT_EQ(true,tree->remove_by_key(10));
    EXPECT_EQ(false,tree->remove_by_key(10));

    EXPECT_EQ(true,tree->remove_by_key(8));
    EXPECT_EQ(false,tree->remove_by_key(8));

    EXPECT_EQ(true, checkIntegrity(tree));

    delete tree;
}

TEST(avl_tree_test, swap_test){
    auto* tree = new avl_tree<int>();
    tree->insert(2);
    tree->insert(5);
    tree->insert(10);
    tree->insert(8);
    tree->insert(12);
    tree->print();
    auto* head = tree->get_data();
    auto val1 = head->right->value;
    auto val2 = head->left->value;
    utils::swap((avl_leaf<int>*) head->right,(avl_leaf<int>*) head->left);
    EXPECT_EQ(val1,head->left->value);
    EXPECT_EQ(val2,head->right->value);
    tree->print();
    delete tree;
}
