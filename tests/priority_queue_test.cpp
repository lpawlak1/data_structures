//
// Created by lukas on 19.06.2021.
//

#include "priority_queue_test.h"
#include "priority_queue.hpp"
#include "gtest/gtest.h"


priority_queue<int>* create_pq(bool min_heap){
    auto* pq = new priority_queue<int>(100, min_heap);
    for(auto i = 0; i < 50; i++){
        pq->insert(i*2);
    }
    return pq;
}

TEST(pq_test, pq_create){
    auto* pq = new priority_queue<int>();
    for(auto i = 0; i < 50; i++){
        pq->insert(50-i);
    }
    delete pq;
}

TEST(pq_test, pq_remove){
    auto* pq = create_pq(true);
    int mini = 0;
    while (pq->size() > 0){
        EXPECT_EQ(mini,pq->pop());
        mini += 2;
    }
    delete pq;
}

TEST(pq_test, pq_max_heap_remove){
    auto* pq = create_pq(false);
    int mini = 2*49;
    while (pq->size() > 0){
        EXPECT_EQ(mini,pq->pop());
        mini -= 2;
    }
    delete pq;
}

TEST(pq_test, pq_change_priority){
    int value = -1;

    auto* pq = create_pq(true);
    auto* node = pq->raw_data()[13];

    EXPECT_EQ(0, pq->top());

    node->change_priority(value);
    EXPECT_EQ(value,pq->pop());

    delete pq;
}