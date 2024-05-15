#include "avl_tree.h"
#include <cassert>
#include <iostream>

void testPrintTree() {
    AVLTree tree;

    std::cout << "������������ ������ ��������� ������...\n";

    // ��������� �������� � ������
    tree.insert(3);
    tree.insert(1);
    tree.insert(4);
    tree.insert(2);
    tree.insert(5);

    // ������� ��������� ������
    tree.printTree();

    std::cout << "�������� ���� ��������� AVL-������ �� ������������ ���������.\n";
}

void testInsertWithPrint() {
    AVLTree tree;

    std::cout << "������������ �������� ������� � ������� ��������� ������:\n";

    // ������ ������� ������
    std::cout << "����������� ������ ������:\n";
    tree.printTree();

    // ������ ������ ��� �������
    int keys[] = { 3, 1, 4, 2, 5 };
    for (int key : keys) {
        std::cout << "������� �������� � ������: " << key << "\n";
        tree.insert(key);
        tree.printTree();
        std::cout << "\n";
    }
}

void testRemoveWithPrint() {
    AVLTree tree;

    std::cout << "������������ �������� �������� � ������� ��������� ������:\n";

    // ������ ������ ��� �������
    int keysToInsert[] = { 3, 1, 4, 2, 5 };
    std::cout << "����������� ���������� ������:\n";
    for (int key : keysToInsert) {
        tree.insert(key);
    }
    tree.printTree();

    // ������ ������ ��� �������� � �������� �������
    int keysToRemove[] = { 5, 2, 4, 1, 3 };
    for (int key : keysToRemove) {
        std::cout << "�������� �������� � ������: " << key << "\n";
        tree.remove(key);
        tree.printTree();
        std::cout << "\n";
    }
}

void testFindMinAndMax() {
    AVLTree tree;

    std::cout << "������������ ������ ������������ � ������������� ���������:\n";

    // ��������� �������� � ������
    int keys[] = { 5, 3, 8, 1, 4, 7, 9 };
    for (int key : keys) {
        tree.insert(key);
    }

    // ������� ��������� ������ ����� ������� ���������
    std::cout << "��������� ������ ����� ������� ���������:\n";
    tree.printTree();

    // ������� � ������� ����������� � ������������ ��������
    Node* minNode = tree.findMin();
    Node* maxNode = tree.findMax();
    std::cout << "����������� ������� � ������: " << (minNode ? std::to_string(minNode->key) : "������ �����") << "\n";
    std::cout << "������������ ������� � ������: " << (maxNode ? std::to_string(maxNode->key) : "������ �����") << "\n";
}

void testFindPredecessorAndSuccessor() {
    AVLTree tree;

    std::cout << "������������ ������ ���������� �������� � ���������� �������� ���������:\n";

    // ��������� �������� � ������
    int keys[] = { 15, 10, 20, 8, 12, 17, 25, 6, 11, 16 };
    for (int key : keys) {
        tree.insert(key);
    }

    // ������� ��������� ������ ����� ������� ���������
    std::cout << "��������� ������ ����� ������� ���������:\n";
    tree.printTree();

    // ����� ��� ������������ ������ predecessor � successor
    int testKeys[] = { 10, 15, 20 };
    for (int key : testKeys) {
        Node* predecessor = tree.findPredecessor(key);
        Node* successor = tree.findSuccessor(key);
        std::cout << "��� ����� " << key << ":\n";
        std::cout << "  Predecessor: " << (predecessor ? std::to_string(predecessor->key) : "���") << "\n";
        std::cout << "  Successor: " << (successor ? std::to_string(successor->key) : "���") << "\n";
    }
}

void runAllTests() {
    std::cout << "\n���� �� ������������ ���������:\n";
    testPrintTree();
    std::cout << "\n���� �� ������� �����:\n";
    testInsertWithPrint();
    std::cout << "\n���� �� �������� �����:\n";
    testRemoveWithPrint();
    std::cout << "\n���� �� ����� ������������ � ������������� �����:\n";
    testFindMinAndMax();
    std::cout << "\n���� �� ����� ��������� �������� � �������� �����:\n";
    testFindPredecessorAndSuccessor();
    std::cout << "\n��� ����� ��������!\n";
}