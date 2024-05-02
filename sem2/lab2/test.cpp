#include "pch.h"
#include "D:\university\pioivis\LABKARRRR2\Header.h"
#include "gtest/gtest.h"
using namespace std;

// ���� ��� ������� Start, ����������� ������������ ������ ������� �� ���������� ������ ������
TEST(TestCaseName, TestName) {
    vector <string> sets;
    sets = SetRecord("in.txt");
    Start(sets);
    EXPECT_EQ(Start(sets), "{6}"); // ��������� ��������� ������ ������� Start
    EXPECT_TRUE(true);
}

// ���� ��� ������� SetRecord, ����������� ��������� ������������� �������� �����
TEST(SetRecordTest, IncorrectInputFile) {
    // ������� ��������� ���� � ������������� �������
    ofstream testfile("testfile.txt");
    testfile << "={1,2,3}" << endl;
    testfile.close();

    // �������� ������� SetRecord �� ��������� �����
    vector<string> result = SetRecord("testfile.txt");

    // ���������, ��� ������� ������� ������ ������
    ASSERT_TRUE(result.empty());
}

// ����� ��� ������� Intersection

// ���������, ��� ��������� ����������� ���� ������ �������� ����� �������� ������ ����������
TEST(IntersectionTest, EmptySets) {
    vector<string> set1 = { "a", "b", "c" };
    vector<string> set2 = {};

    vector<string> result = Intersection(set1, set2);

    ASSERT_TRUE(result.empty());
}

// ���������, ��� ���� � ���� �������� ��� ����� ���������, �� ��������� ����������� ����� ������ ���� ������
TEST(IntersectionTest, NoCommonElements) {
    vector<string> set1 = { "a", "b", "c" };
    vector<string> set2 = { "x", "y", "z" };

    vector<string> result = Intersection(set1, set2);

    ASSERT_TRUE(result.empty());
}

// ���������, ��� ���� � ���� �������� ���� ����� ��������, �� ��������� ����������� ������ ��������� ������ ��� ����� ��������
TEST(IntersectionTest, CommonElementsExist) {
    vector<string> set1 = { "a", "b", "c", "d" };
    vector<string> set2 = { "b", "c", "e" };

    vector<string> expected_result = { "b", "c" };
    vector<string> result = Intersection(set1, set2);

    ASSERT_EQ(expected_result, result);
}
