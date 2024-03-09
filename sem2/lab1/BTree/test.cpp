#include "pch.h"
#include "gtest/gtest.h" 
#include "BTREE.hpp" 

// ������������ ������� ������ � B-������
TEST(BTreeTest, SearchTest) {
    BTree tree(5);

    tree.insert(17);
    tree.insert(8);
    tree.insert(28);
    tree.insert(14);

    ASSERT_TRUE(tree.search(7) == nullptr); // �������, ��� ������� 7 �� ������
    tree.insert(7);
    ASSERT_TRUE(tree.search(7) != nullptr); // �������, ��� ������� 7 ������

    tree.insert(10);
    tree.insert(15);
    tree.insert(22);
    tree.insert(18);

    ASSERT_TRUE(tree.search(15) != nullptr); // �������, ��� ������� 15 ������
    ASSERT_TRUE(tree.search(20) == nullptr); // �������, ��� ������� 20 �� ������
    ASSERT_TRUE(tree.search(22) != nullptr);// �������, ��� ������� 22 ������
    ASSERT_TRUE(tree.search(5) == nullptr);// �������, ��� ������� 5 �� ������
}

// ������������ ������� ������� � B-������
TEST(BTreeTest, InsertTest) {
    BTree tree(5);

    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(10);
    tree.insert(15);
    tree.insert(22);
    tree.insert(18);
    tree.insert(16);
    tree.insert(2);
    tree.insert(38);
    tree.insert(17);
    tree.insert(8);
    tree.insert(28);
    tree.insert(14);

    // ���������, ��� �������� ������������� ���������
    ASSERT_TRUE(tree.search(14) != nullptr);
    ASSERT_TRUE(tree.search(10) != nullptr);
    ASSERT_TRUE(tree.search(15) != nullptr);
    ASSERT_TRUE(tree.search(38) != nullptr);
    ASSERT_TRUE(tree.search(17) != nullptr);
    ASSERT_TRUE(tree.search(2) != nullptr);
    ASSERT_TRUE(tree.search(28) != nullptr);
}

// ������������ ������� �������� �� B-������
TEST(BTreeTest, RemoveTest) {
    BTree tree(5);

    tree.insert(1);
    tree.insert(4);
    tree.insert(7);
    tree.insert(10);
    tree.insert(15);
    tree.insert(22);
    tree.insert(18);
    tree.insert(25);
    tree.insert(30);
    tree.insert(8);
    tree.insert(17);
    tree.insert(13);
    tree.insert(28);
    tree.insert(14);

    //���������, ���� �� ������� 15 � ������
    ASSERT_TRUE(tree.search(15) != nullptr);
    // ������� ������� �� ������
    tree.remove(15);
    // ���������, ��� ������� ������������� ������
    ASSERT_TRUE(tree.search(15) == nullptr);

    //���������, ���� �� ������� 14 � ������
    ASSERT_TRUE(tree.search(14) != nullptr);
    // ������� ������� �� ������
    tree.remove(14);
    // ���������, ��� ������� ������������� ������
    ASSERT_TRUE(tree.search(14) == nullptr);

    /*���������, ���� �� ������� 17 � ������*/
    ASSERT_TRUE(tree.search(17) != nullptr);
  /*   ������� ������� �� ������*/
    tree.remove(17);
    /* ���������, ��� ������� ������������� ������*/
    ASSERT_TRUE(tree.search(17) == nullptr);
}

// ������ ���� ������
int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
