#include "pch.h"
#include <gtest/gtest.h>
#include "../priorityQueue/priorityQueue.h"
using namespace std;

//���� �� ������� � ����������
TEST(PriorityQueueTest, InsertAndExtract1) {
    PriorityQueue queue;

    EXPECT_TRUE(queue.isEmpty());

    queue.insert(10);
    queue.insert(5);
    queue.insert(20);

    EXPECT_FALSE(queue.isEmpty());
    EXPECT_EQ(queue.extract(), 5);
    EXPECT_EQ(queue.extract(), 10);
    EXPECT_EQ(queue.extract(), 5);
    EXPECT_TRUE(queue.isEmpty());
}

//��� ���� �� ������� � ����������
TEST(PriorityQueueTest, InsertAndExtract2) {
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(5);
    pq.insert(20);
    pq.insert(15);
    pq.insert(25);

    EXPECT_EQ(pq.extract(), 25);
    EXPECT_EQ(pq.extract(), 20);
    EXPECT_EQ(pq.extract(), 15);
    EXPECT_EQ(pq.extract(), 10);
    EXPECT_EQ(pq.extract(), 5);

    EXPECT_TRUE(pq.isEmpty());
}

//���� �� ������� � ���������� � ����������� ����������
TEST(PriorityQueueTest, InsertAndExtractWithDuplicates) {
    PriorityQueue pq;
    pq.insert(10);
    pq.insert(5);
    pq.insert(10);
    pq.insert(8);

    EXPECT_EQ(pq.extract(), 10);
    EXPECT_EQ(pq.extract(), 10);
    EXPECT_EQ(pq.extract(), 8);
    EXPECT_EQ(pq.extract(), 5);
    EXPECT_TRUE(pq.isEmpty());
}

//���� �� ���������� �� ������ �������
TEST(PriorityQueueTest, ExtractFromEmptyQueue) {
    PriorityQueue pq;

    EXPECT_THROW(pq.extract(), std::out_of_range);
}

//���� �� ������� � ���������� � �������������� ����������
TEST(PriorityQueueTest, InsertWithNegativeNumbers) {
    PriorityQueue pq;

    pq.insert(10);
    pq.insert(-5);
    pq.insert(25);
    pq.insert(-10);
    pq.insert(-2);

    EXPECT_EQ(pq.extract(), 25);
    EXPECT_EQ(pq.extract(), 10);
    EXPECT_EQ(pq.extract(), -2);
    EXPECT_EQ(pq.extract(), -5);
    EXPECT_EQ(pq.extract(), -10);
    EXPECT_TRUE(pq.isEmpty());
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}