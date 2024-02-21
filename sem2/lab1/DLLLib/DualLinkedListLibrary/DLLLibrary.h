//DLLLibrary.h
#pragma once
namespace DLLLibrary
{ // ��������� ���� �� ��� �����
    struct Node {
        int value;
        Node* next;
        Node* prev;

        // ����������� �����
        Node(int v, Node* n, Node* p) {
            value = v;
            next = n;
            prev = p;
        }
    };

    // ����� ���������������� �������� ������
	class LinkedList {

    private:
        Node* head;
        Node* tail;
        int elementCount;

    public:
        //������� ������ ���������� ������
        LinkedList();

        //���������� ������
        ~LinkedList();

        // ���������� ������ (���������)
        void Sort();

        //����� (�������) ��������� ������� ����
        Node* getNode(int index);

        //����� ��� ����������� ���� �������
        LinkedList merge(LinkedList& otherList) const;

        //����� ��� ����������� ���� �������
        LinkedList intersection(LinkedList& otherList) const;

        // �������� 
        int getValue (int index);

        // ����� (�������), ������������ ���-�� ���������� � ������
        int GetSize() const;

        // ����� (�������), �����������, �������� �� ������ ������
        bool CheckEmpty() const;

        //������� ���� (��������) ����� ��������� ����
        void insertAfter(Node* elem, int value);

        //������� ���� (��������) ����� �������� �����
        void insertBefore(Node* elem, int value);

        //�������� ����
        void erase(Node* elem);

        //�������� (�������) ���� � ������ ������
        void pushFront(int value);

        //������� ���� � ������ ������
        void popFront();

        //������� ���� � ����� ������
        void popBack();

        //�������� (�������) ���� � ����� ������
        void pushBack(int value);

        //������� ������ � �������
        void print() const;

        //�������� �������� ������� ����
        int getFront() const;
        
        //�������� �������� ���������� ����
        int getBack() const;
	};
}