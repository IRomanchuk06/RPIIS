#pragma once
#include <vector>
#include <string>
using namespace std;
class suffix_array {
public:
	suffix_array(string str); //��������� ������ � �������� ��������� ��� �������� ������� ������
	void view();
	string get_lcp(); //Longest common prefix
	string get_scs(); //���������� ����������� �����
private:
vector<string> suffixes;
vector<string> shifts;
};