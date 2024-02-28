#include <iostream>
#include <cassert>
#include "queue.h"

int main() {
    setlocale(LC_ALL, "RU");
    Queue queue;

    // ���� 1: �������� ������ �������
    assert(queue.isEmpty());
    std::cout << "���� 1 �������" << std::endl;

    // ���� 2: ���������� ��������� � �������
    queue.enqueue(10);
    queue.enqueue(-20);
    queue.enqueue(30);
    std::cout << "���� 2 �������" << std::endl;

    // ���� 3: �������� ������� �������
    assert(queue.size() == 3);
    std::cout << "���� 3 �������" << std::endl;

    // ���� 4: �������� �������� � ������ �������
    assert(queue.front() == 10);
    std::cout << "���� 4 �������" << std::endl;

    // ���� 5: ���������� ��������� �� �������
    assert(queue.dequeue() == 10);
    assert(queue.dequeue() == -20);
    std::cout << "���� 5 �������" << std::endl;

    // ���� 6: �������� ������� ������� ����� ����������
    assert(queue.size() == 1);
    std::cout << "���� 6 �������" << std::endl;

    // ���� 7: �������� �������� � ������ ������� ����� ����������
    assert(queue.front() == 30);
    std::cout << "���� 7 �������" << std::endl;

    // ���� 8: ���������� ���������� �������� � �������� ������� �������
    assert(queue.dequeue() == 30);
    assert(queue.isEmpty());
    std::cout << "���� 8 �������" << std::endl;

    // ���� 9: ���� �� ���������� � ���������� �������� ���������� ���������
    for (int i = 0; i < 1000; ++i) {
        queue.enqueue(i);
    }
    assert(queue.size() == 1000);
    for (int i = 0; i < 1000; ++i) {
        assert(queue.dequeue() == i);
    }
    assert(queue.isEmpty());
    std::cout << "���� 9 �������" << std::endl;

    // ���� 10: ���� �� ������� �������
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    assert(!queue.isEmpty());
    queue.clear();
    assert(queue.isEmpty());
    std::cout << "���� 10 �������" << std::endl;

    // ���� 11: ������� ���������� �������� �� ������ �������
    assert(queue.isEmpty());
    try {
        queue.dequeue();
        // ���� ���������� ������ �������, ���� �� �������
        std::cout << "���� 11 �� �������" << std::endl;
    }
    catch (...) {
        // ���� ���� ������������� ����������, �� ���� �������
        std::cout << "���� 11 �������" << std::endl;
    }

    std::cout << "��� ����� ��������!" << std::endl;

    return 0;
}