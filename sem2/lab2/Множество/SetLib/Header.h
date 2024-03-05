#pragma once

namespace SetLib
{
   //�����, �������������� �������� ��������� ������������ ��� ������������� ����� ��������
    std::vector<std::vector<int>> cartesianProduct(const std::vector<std::vector<int>>& sets);

    // ������� ��� ������ ��������� � �������
    void printSet(const std::vector<int>& set);

    // ����� ��� �������� � ������������� ������������� ����� ��������
    std::vector<std::vector<int>> CreateSets(int num);
}