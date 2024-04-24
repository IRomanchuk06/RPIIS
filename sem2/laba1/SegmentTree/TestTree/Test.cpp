#include <iostream>
#include "C:\Users\roma0\source\repos\SegmentTree\SegmentTree\TreeHead.h"  // �������� �� ���������� ���� � ����� TreeHead.h

int main() {
    std::vector<int> arr = { 1, 2, 3, 2, 1, 3, 1, 1, 2, 3, 3, 3 };
    int N = arr.size();

    // ������� ������ �������� ��� ������� ����������� �����
    std::vector<SegmentTree> trees(4, SegmentTree(N));
    for (int i = 0; i < N; ++i) {
        trees[arr[i]].build(arr, 1, 0, N - 1);
    }

    // ����������� ���������� ��������� ����� 2 � ������� [1, 4]
    int l = 1, r = 4, x = 2;
    std::cout << "����� " << x << " ����������� � ������� [" << l << ", " << r << "] "
        << trees[x].query(1, 0, N - 1, l, r) << " ���.\n";

    return 0;
}