#include <iostream>
#include "Source.h"

bool test_build_tree() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]); //����� ���������
    Drevo* root = build_tree(arr, 0, size - 1);

    // �������� ��������� ������
    if (root->start != 0 && root->end != size - 1 && root->sum != 15) {
        std::cout << "build_tree ���� �� �������: ������������ ��������� ������" << std::endl;
        return false;
    }

    if (root->left->start != 0 && root->left->end != 2 && root->left->sum != 6) {
        std::cout << "build_tree ���� �� �������: ������������ ��������� ������ �������" << std::endl;
        return false;
    }

    if (root->right->start != 3 && root->right->end != 4 && root->right->sum != 9) {
        std::cout << "build_tree ���� �� �������: ������������ ��������� ������� �������" << std::endl;
        return false;
    }

    delete root; // ������������ ������
    return true;
}

bool test_update() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    Drevo* root = build_tree(arr, 0, size - 1);

    update(root, 1, 3, 10);
    // �������� ���������� ����������
    if (root->left->sum != 21 || root->sum != 36) {
        std::cout << "update ���� �� �������: ������������ ����� ����� ����������" << std::endl;
        return false;
    }

    delete root; // ������������ ������
    return true;
}

bool test_sum_on_range() {
    int arr[] = { 1, 2, 3, 4, 5 };
    int size = sizeof(arr) / sizeof(arr[0]);
    Drevo* root = build_tree(arr, 0, size - 1);

    int sum = sum_on_range(root, 1, 3);

    // �������� ����������� �����
    if (sum != 9) {
        std::cout << "sum_on_range ���� �� �������: ������������ �����" << std::endl;
        return false;
    }

    delete root; // ������������ ������
    return true;
}

int main() {
    setlocale(LC_ALL, "RU");
    bool all_tests_pass = true;

    if (!test_build_tree()) {
        all_tests_pass = false;
    }

    if (!test_update()) {
        all_tests_pass = false;
    }

    if (!test_sum_on_range()) {
        all_tests_pass = false;
    }

    if (all_tests_pass) {
        std::cout << "��� ����� �������� �������!" << std::endl;
    }

    return 0;
}