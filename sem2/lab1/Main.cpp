#include "Header.h"
using namespace std;
int main()
{
	system("chcp 1251 > nul");
	Treap tree;
	//T��� 1:
	if (!tree.root) cout << "���� 1 �������\n";
	// ���� 2:
	vector <int> keys = {1,3, 2, 4 };
	tree.buildTree(keys);
	tree.outTree(tree.root,0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	for (int key: keys)
	{
		if (tree.search(tree.root, key)-> key!= key)
		{
			cout << "������";
			return 0;
		}
	}
	cout << "���� 2 �������\n";
	// ���� 3:
	for (int key : keys)
	{
		tree.erase(tree.root, key);
	}
	if(tree.root == nullptr) cout << "���� 3 �������\n";
	//���� 4:
	tree.insert(9, 5);
	if (tree.search(tree.root, 9)->key == 9) cout << "���� 4 �������\n";
	tree.erase(tree.root, 9);
	//���� 5:
	vector <int> keys2 = { 3, 5, 7, 8};
	vector <int> prioritys = { 5, 11, 4, 2};
	Treap tree2;
	tree2.buildTree(keys2, prioritys);
	for (int key : keys2)
	{
		if (tree2.search(tree2.root, key)->key != key)
		{
			cout << "������";
			return 0;
		}
	}
	tree2.outTree(tree2.root, 0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << "���� 5 �������\n";
	//���� 6:
	Treap uniontree,tree1;
	tree1.buildTree(keys);
	uniontree.root = uniontree.unite(tree1.root, tree2.root);
	uniontree.outTree(uniontree.root,0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << "���� 6 �������\n";
	//���� 7:
	Treap intersection,tree3;
	tree3.buildTree(keys);
	tree3.insert(5);
	tree3.insert(7);
	intersection.root = intersection.intersect(tree2.root, tree3.root);
	intersection.outTree(intersection.root,0);
	for (int i = 0; i < 100; i++)
	{
		cout << '-';
	}
	cout << endl;
	cout << "���� 7 �������\n";
}