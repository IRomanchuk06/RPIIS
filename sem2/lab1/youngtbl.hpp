#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

class YoungTableau
{
    private:
        // ����� ������� ���� ��������� � ���� ������� ��������
        std::vector<std::vector<int>> table;

    public:
        // ������������� �������
        void initialize(int row_number)
        {
            // ���� ������� ��������, ��� �������������� ���������
            if (!table.empty())
            {
                for (auto& row : table)
                    row.clear();
                table.clear();
            }
            // ������� �������� �� ������� ���������� ������ �����
            for (int i = 0; i < row_number; i++)
            {
                table.push_back({});
            }
        }

        // ����������� ���������� ����� � �������
        size_t width()
        {
            return table.size();
        }

        // ���������� �������� � ����������� ������ �������
        void add(int line_number, int element)
        {
            table[line_number-1].push_back(element);
        }

        // �������� ������� ��������� �������� � �������
        void remove(int element)
        {
            // ���������� "���������� �� ������ ������� � �������"
            bool in_table = 0;
            
            // ������ �� ������ ������ �������
            for (auto& row : table)
            {
                auto it = std::find(row.begin(), row.end(), element);

                // ���� ������� ������, ������� ��� � ��������� ���������
                if (it != row.end())
                {
                    row.erase(it);
                    std::cout << "�� ������� ��� ����� ������ ������������� ������� " << element << ".\n";
                    break;
                }
            }
            // ���� ������� �������� � ������� ���, ������� ��������������� ���������
            if (!in_table)
                std::cout << "������� �������� ��� � �������.\n";
        }

        // �������� ���� ��������� �������� � �������
        void removeAll(int element)
        {
            // ���������� "���������� �� ������ ������� � ������� � ���������� �� ����� ������"
            bool in_table = 0;

            for (auto& row : table)
            {
                // ������ �� ������ ������� ���������� ������� ���, ����� ������� �������� � ������ �� ��������
                while(1)
                {
                    auto it = std::find(row.begin(), row.end(), element);

                    // ���� ������� ������, ������� ���
                    if (it != row.end())
                    {
                        row.erase(it);
                        in_table = 1;
                    }
                    // ����� ��������� � ��������� ������
                    else break;
                }
            }
            // ���� ������� �������� � ������� ���, ������� ��������������� ���������
            if (!in_table)
                std::cout << "������� �������� ��� � �������.\n";
            else
                std::cout << "�� ������� ���� ������� ��� �������� " << element << ".\n";
        }

        // ����� ������� �� �����
        void print()
        {
            // ���� ������� �����, �������� �� ����
            if (table.size() == 0)
                std::cout << "\n������� �����.\n";
            // ����� ������� � �������
            else
            {
                std::cout << "\n������� ����:\n";
                for (auto& row : table)
                {
                    for (int element : row)
                    {
                        std::cout << element << " ";
                    }
                    std::cout << "\n";
                }
            }
        }

        // ����� ������� � ����
        void printToFile(std::string filename)
        {
            std::ofstream fout(filename);
			// ���� ������� �����, �������� �� ����
            if (table.size() == 0)
                fout << "������� �����.";
            // ����� ������� � �������
            else
            {
                fout << "������� ����:";
                for (auto& row : table)
                {
                    fout << "\n";
					for (int element : row)
                    {
                        fout << element << " ";
                    }
                }
            }

            std::cout << "������� ���� �������� � " << filename << ".\n";
        }
};
