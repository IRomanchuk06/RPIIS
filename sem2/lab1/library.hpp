#include <sstream>
#include <queue>
#include <iostream>

#ifndef LIBRARY_HPP
#define LIBRARY_HPP

using namespace std;

// ����� ���� �-������
class BTreeNode
{
	int* keys; // ������ ������
	int t;	 // �������� ������ (�� ���� ������� ���-�� ������ � ���� � ���-�� �������� ����)
	BTreeNode** C; // ������ ���������� �� �����
	int n;	 // ������� ���������� ������
	bool leaf; // ������, ����� ���� �������� ��������

public:

	BTreeNode(int _t, bool _leaf); // �����������

	// ������� ��� ������ ����� � ���������, ������ �������� �������� ���� ����.
	BTreeNode* search_key(int k); // ���������� NULL, ���� k �����������.

	// �������������� �������, ������� ���������� ������ ������� �����, ������� ������ ��� ����� k
	int findKey(int k);

	// ��������������� ������� ��� ������� ������ ����� � ��������� � ������
	// ���� ����. ��������������, ��� ���� ������ ���� ��������, ����� ��� ������� ����������
	void insertNonFull(int k);

	// ��������������� ������� ��� ���������� ������� y ����� ����.
	//  ������� ������ ���� �����������, ����� ��� ������� ����������
	void splitChild(int i, BTreeNode* y);

	// ������� ��� �������� ����� k � ��������� � ������ ���� ����.
	void delete_key(int k);

	// ��������������� ������� ��� �������� �����, �������� �� idx-� ������� ����, ������� �������� ������
	void delete_from_leaf(int idx);

	// ��������������� ������� ��� �������� �����, �������� �� idx-� ������� ����, ������� �� �������� ������
	void delete_from_nonleaf(int idx);

	// ������� ��� ��������� ��������������� �����, ��� ���� ����� �� idx-� ������� ����
	int getPred(int idx);

	// ������� ��� ��������� ��������� �����, ��� ���� ����� �� idx-� ������� ����
	int getSucc(int idx);

	// ������� ��� ���������� ��������� ����, �������� �� idx-�� ������� � ������� C[], ���� � ����� ��������� �������� ������ t-1 ������
	void fill(int idx);

	// ������� ��� ������������� ����� �� C[idx-1]-�� ���� � ���������� ��� � C[idx]-� ����
	void borrowFromPrev(int idx);

	// ������� ��� ������������� ����� �� C[idx+1]-�� ���� � ���������� ��� � C[idx]-� ����
	void borrowFromNext(int idx);

	// ������� ������� idx-�� ��������� ���� � (idx+1)-� �������� ��������� ���� ����
	void merge(int idx);

	friend class BTree;
	friend class PrettyPrint;
};

class BTree
{
	BTreeNode* root; // ��������� �� ������
	int t; // �������� ������
public:

	// ����������� (�������������� ������ ��� ������)
	BTree(int _t)
	{
		root = NULL;
		t = _t;
	}

	//������� ������� ��� ������ ����� � ���� ������
	BTreeNode* search_key(int k)
	{
		return (root == NULL) ? NULL : root->search_key(k);
	}

	// �������� ������� ������� ������ ����� � B-������
	void insert_key(int k);

	// �������� ������� �������� ����� � B-������
	void delete_key(int k);

	friend class PrettyPrint;
};

//������� �����, ������� ������� ��� ����������� ������� ������ :)
class PrettyPrint
{
	//������� ���������� ���������, ������������ ��� �������� ���������� � ������ ���� � ������
	struct NodeInfo
	{
		string text; //��������� ������������� ������ ����
		unsigned text_pos, text_end;
	};

	typedef vector<NodeInfo> LevelInfo;

	vector<LevelInfo> levels;

	//������� ��� ������������� ������ ���� � ���� ������.
	string node_text(int const keys[], unsigned key_count);

	void before_traversal()
	{
		levels.resize(0);
		levels.reserve(10);
	}

	//������� ��� ������������ ������ ����� B-������ � ����� ���������� � ������ ���� ��� ����������� ������.
	void visit(BTreeNode const* node, unsigned level = 0, unsigned child_index = 0);

	//������� ��� ���������� ������ ������ � ������ ��������� ���������� �� �����
	void after_traversal();

public:

	//���� ������
	void print(BTree const& tree)
	{
		before_traversal();
		visit(tree.root);
		after_traversal();
	}
};

#endif