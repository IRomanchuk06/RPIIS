#ifndef AVL_TREE_H
#define AVL_TREE_H

#include "avl_node.h"
#include <string>

class AVLTree {
public:
    AVLTree(); // �����������
    ~AVLTree(); // ����������

    // �������� �������� � AVL-�������
    void insert(int key); // ������� �����
    void remove(int key); // �������� �����
    Node* find(int key) const; // ����� ���� �� �����
    bool isEmpty() const; // �������� ������ �� �������
    void printTree(); // ����� ��������� ������ � �������
    int height(); // ��������� ������ ������
    Node* findMin() const; // ������� ����������� �������
    Node* findMax() const; // ������� ������������ �������
    Node* findSuccessor(int key) const; // ������� ��������� ������� ������� ��� ��������� �����
    Node* findPredecessor(int key) const; // ������� ��������� ������� ������� ��� ��������� �����

private:
    Node* root; // �������� ���� ������

    // ��������������� ������� ��� ����������� ���������� �������� ��������
    Node* insert(Node* node, int key); // ������� ����� � ���������
    Node* remove(Node* node, int key); // �������� ����� �� ���������
    Node* find(Node* node, int key) const; // ����� ���� �� ����� � ���������
    void destroyTree(Node* node); // ����������� �������� ���� ����� ������

    // ��������������� ������� ��� ����������� ������� ������
    Node* balance(Node* node); // ������������ ����
    Node* rotateLeft(Node* node); // ����� ��������
    Node* rotateRight(Node* node); // ������ ��������
    int getBalanceFactor(Node* node); // ��������� ������� ������� ����
    void fixHeight(Node* node); // ���������� ������ ����

    // ��������������� ������� ��� ������ � ������
    Node* findMin(Node* node); // ����� ���� � ����������� ������
    Node* removeMin(Node* node); // �������� ���� � ����������� ������
    void printTreeHelper(const Node* node, std::string indent, bool last) const; // ��������������� ������� ��� ������ ������
    int height(Node* node) const; // ���������� ������ ���������
};

#endif // AVL_TREE_H
