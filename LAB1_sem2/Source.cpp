#include "Header.h"
#include <iostream>
using namespace N;
int main() {
    bst* tree = new bst;
    bst* tree1 = new bst;
    int keys[] = { 23, 12, 31, 3, 15, 7, 29, 88, 53 };

    // ������ �������� ������ �� ������� � ������� ������� insert
    for (const int& key : keys)
        tree->Insert(key);

    std:: cout << "Tree keys: ";
    tree->bypass();
    

    // ������ ������� ������ �� ������� � ������� ��������� �������
    /*tree1->root = tree1->CreateBSTarr(keys, 0, 8);
    std::cout << "Tree keys: ";
    tree1->bypass();
    */

    // �������� ��������
    /*tree->Remove(7);

    std::cout << "Tree keys after remove: ";
    tree->bypass();
    */

    // ����� ��������
   /*bool b = tree->search(7);
    if (b) {
        std::cout << "found";
    }
    else std::cout << "not found";
    */




}