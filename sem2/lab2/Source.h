#pragma once
struct Drevo {
    int start; //������ ������ �������
    int end;   //������ ����� �������
    int sum;   //����� ��������� � start �� end
    Drevo* left; //��������� �� ������ �������
    Drevo* right; //��������� �� ������� �������
};
Drevo* build_tree(int* , int , int );
void update(Drevo* , int , int , int );
int sum_on_range(Drevo* , int , int );
