#include "rbtree.h"

using namespace std;

void insertNode(Node*& root, int key) {

	Node* nodetmp = root;

	while (true) {							//����� ����� ��� ������� ������ ���� �� ������ ��� �����
		if (key < nodetmp->key) {		
			
			if (nodetmp -> left == nullptr) {
				nodetmp->left = new Node{ key, nodetmp, nullptr, nullptr, 1 };
				insert_fix(nodetmp->left, root);
				return;
			}
			nodetmp = nodetmp->left;
		}

		else if (key > nodetmp->key) {

			if (nodetmp -> right == nullptr) {
				nodetmp->right = new Node{ key, nodetmp, nullptr, nullptr, 1 };
				insert_fix(nodetmp->right, root);
				return;
			}
			nodetmp = nodetmp->right;
		}
		else {
			cout << "���� � ����� ������ ��� ����������!";
			return;
		}
	}
}

void insert_fix(Node* node, Node*& root) {
		while (node->parent->IsRed) {
			//���� ����������� � ����������� ����� �� ������ ���� �������� ���� ������� ������� ��� ��� �� ������ :(

			/*���������� ���������� ��������� ������� �� ������������ ���� ���� �� ��������� � ������� ����*/

			/*���� ���� - ����� �������*/
			if (node->parent == node->parent->parent->left) {	 
																	
				/*����� �� �������� �� nullptr �������� (��� ��� �������� � ������) ��������� ���������� �� ���� � ������ ���� */
				if (node->parent->parent->right != nullptr) {

					/*���� ���� ���������, �� ���������: ������� �� ��?*/
					if (node->parent->parent->right->IsRed) {

						/*���� ���� �������, �� ���������� ������ ����������� ��������� �������*/
						node->parent->IsRed = 0;
						node->parent->parent->right->IsRed = 0;
						node->parent->parent->IsRed = 1;

						node = node->parent->parent;
					}
					else
						/*���� ���� ������, ���������� ��������� ������� ��� ���� ���
						(���� ���������� �������� ���� �� �� �������)*/
						goto p1;
				}
				else {
				p1:
					/*���� ���� ��������� ������ �� ���� �� ����������� �������,
					����� �������� ��� ��������� � "�������� ������"*/
					if (node == node->parent->right) {
						left_rotate(root, node->parent->key);
						node = node->left;
					}

					/*"������� ������"*/
					right_rotate(root, node->parent->parent->key);

					node->parent->right->IsRed = 1;
					node->parent->IsRed = 0;

					node = node->parent;
				}
			}

			/*���� ���� - ������ �������*/
			else {

				/*����� �� �������� �� nullptr �������� (��� ��� �������� � ������) ��������� ���������� �� ���� � ������ ���� */
				if (node->parent->parent->left != nullptr) {

					/*���� ���� ���������, �� ���������: ������� �� ��?*/
					if (node->parent->parent->left->IsRed) {

						/*���� ���� �������, �� ���������� ������ ����������� ��������� �������*/
						node->parent->IsRed = 0;

						node->parent->parent->left->IsRed = 0;

						node->parent->parent->IsRed = 1;

						node = node->parent->parent;
					}
					else 
						/*���� ���� ������, ���������� ��������� ������� ��� ���� ���
						(���� ���������� �������� ���� �� �� �������)*/
						goto p2;
				}
				else {

					p2:
					/*���� ���� ��������� ����� �� ���� �� ����������� �������,
					����� �������� ��� ��������� � "�������� ������"*/
					if (node == node->parent->left) {
						right_rotate(root, node->parent->key);
						node = node->right;
					}

					/*"������� ������"*/
					left_rotate(root, node->parent->parent->key);

					node->parent->left->IsRed = 1;
					node->parent->IsRed = 0;

					node = node->parent;
				}

			}
			/*������������ ���������� ������� � ������ ����, ��������� ��� ������ � ����� ������*/
			root->IsRed = 0;

			/*����� ����� �� ������� ������ � ������ ������ �� nullptr, ��������� ���� ���� ��� �������� ������ �������*/
			if (node->parent == nullptr)
				break;
		}
}

void deleteNode(Node*& root, int key) {
	Node* node = root;

	while (node != nullptr)
		if (key < node->key)
			node = node->left;
		else if (key > node->key)
			node = node->right;
		else
			break;

	if (node == nullptr) {
		cout << "��� ������� � ����� ������!";
		return;
	}

	del(root, node);
}

void del(Node*& root, Node*node) {

	/*�������� ������� ������� ��� ��������*/
	if (node->IsRed && node->left == nullptr && node->right == nullptr) {
		clearNode(node);
	}
	/*�������� ������� � ������ ��������*/
	else if (node -> right != nullptr) {
		Node* nodetmp = node->right;

		while (nodetmp->left != nullptr)
			nodetmp = nodetmp->left;

			int tmp = nodetmp->key;
			nodetmp->key = node->key;
			node->key = tmp;

			del(root, nodetmp);
	}
	/*�������� ������� � ����� ��������*/
	else if (node->left != nullptr) {
		Node* nodetmp = node->left;

		while (nodetmp->right != nullptr)
			nodetmp = nodetmp->right;

		int tmp = nodetmp->key;
		nodetmp->key = node->key;
		node->key = tmp;

		del(root, nodetmp);
	}

	/*�������� ������ ������� ��� ��������*/
	else if (!node->IsRed && node->left == nullptr && node->right == nullptr) {

		/*���� �������� ������� - �������*/
		if (node->parent->IsRed) {
			/*���� ���� - ������ �������*/
			if (node == node->parent->right) {
				/*���� � ����� ���� ���� �� ���� ������� ������� ����� ��� ������*/
				if (node->parent->left->right != nullptr && node->parent->left->right->IsRed) {
					left_rotate(root, node->parent->left->key);
					right_rotate(root, node->parent->key);

					node->parent->IsRed = 0;

					clearNode(node);
				}
				else if (node->parent->left->left != nullptr && node->parent->left->left->IsRed) {
					right_rotate(root, node->parent->key);

					node->parent->IsRed = 0;
					node->parent->parent->IsRed = 1;
					node->parent->parent->left->IsRed = 0;

					clearNode(node);
				}
				/*���� � ����� ���� ��� ������� ��������*/
				else {
					node->parent->left->IsRed = 1;
					node->parent->IsRed = 0;

					clearNode(node);
				}
			}
			/*���� ���� - ����� �������*/
			else {
				/*���� � ����� ���� ���� �� ���� ������� ������� ����� ��� ������*/
				if (node->parent->right->left != nullptr && node->parent->right->left->IsRed) {
					right_rotate(root, node->parent->right->key);
					left_rotate(root, node->parent->key);

					node->parent->IsRed = 0;

					clearNode(node);
				}
				/*���� � ����� ���� ������ ���� ������� ������� ������*/
				else if (node->parent->right->right != nullptr && node->parent->right->right->IsRed) {
					left_rotate(root, node->parent->key);

					node->parent->IsRed = 0;
					node->parent->parent->IsRed = 1;
					node->parent->parent->right->IsRed = 0;

					clearNode(node);
				}
				/*���� � ����� ���� ��� ������� ��������*/
				else {
					node->parent->right->IsRed = 1;
					node->parent->IsRed = 0;

					clearNode(node);
				}
			}
		}
		/*���� �������� ������� - ר����*/
		else {
			/*���� ���� - ������ �������*/
			if (node == node->parent->right) {
				/*���� ���� ������� - �������*/
				if (node->parent->left->IsRed) {
					/*���� � ������� ���������� ������� ���� ���� �� ���� ������� �������*/
					if ((node->parent->left->right->left != nullptr && node->parent->left->right->left->IsRed) ||
						(node->parent->left->right->right != nullptr && node->parent->left->right->right->IsRed)) {
						left_rotate(root, node->parent->left->key);
						right_rotate(root, node->parent->key);

						if (node->parent->parent->left->right != nullptr && node->parent->parent->left->right->IsRed)
							node->parent->parent->left->right->IsRed = 0;
						else
							node->parent->parent->left->IsRed = 0;

						clearNode(node);
					}
					/*���� � ���������� ������� ��� ������� ��������*/
					else {
						right_rotate(root, node->parent->key);
						node->parent->parent->IsRed = 0;
						node->parent->left->IsRed = 1;

						clearNode(node);
					}
				}
				/*���� ���� ������� - ר����*/
				else{
					/*���� � ����� ���� ������ ������� �������*/
					if (node->parent->left->right != nullptr && node->parent->left->right->IsRed) {
						left_rotate(root, node->parent->left->key);
						right_rotate(root, node->parent->key);

						node->parent->parent->IsRed = 0;

						clearNode(node);
					}
					/*���� � ����� ���� ����� ������� �������*/
					else if (node->parent->left->left != nullptr && node->parent->left->left->IsRed) {
						right_rotate(root, node->parent->key);

						node->parent->parent->left->IsRed = 0;

						clearNode(node);
					}
					/*���� � ����� ��� ������� ���������*/
					else {
						node->parent->left->IsRed = 1;
						clearNode(node);
					}
				}
			}
			/*���� ���� - ����� �������*/
			else {
				/*���� ���� ������� - �������*/
				if (node->parent->right->IsRed) {
					/*���� � ������ ���������� ������� ���� ���� �� ���� ������� �������*/
					if ((node->parent->right->left->right != nullptr && node->parent->right->left->right->IsRed) ||
						(node->parent->right->left->left != nullptr && node->parent->right->left->left->IsRed)) {
						right_rotate(root, node->parent->right->key);
						left_rotate(root, node->parent->key);

						if (node->parent->parent->right->left != nullptr && node->parent->parent->right->left->IsRed)
							node->parent->parent->right->left->IsRed = 0;
						else
							node->parent->parent->right->IsRed = 0;

						clearNode(node);
					}
					/*���� � ���������� ������� ��� ������� ��������*/
					else {
						left_rotate(root, node->parent->key);
						node->parent->parent->IsRed = 0;
						node->parent->right->IsRed = 1;

						clearNode(node);
					}
				}
				/*���� ���� ������� - ר����*/
				else {		
					/*���� � ����� ���� ����� ������� �������*/
					if (node->parent->right->left != nullptr && node->parent->right->left->IsRed) {
						right_rotate(root, node->parent->right->key);
						left_rotate(root, node->parent->key);

						node->parent->parent->IsRed = 0;

						clearNode(node);
					}
					/*���� � ����� ���� ������ ������� �������*/
					else if (node->parent->right->right != nullptr && node->parent->right->right->IsRed) {
						right_rotate(root, node->parent->key);

						node->parent->parent->right->IsRed = 0;

						clearNode(node);
					}
					/*���� � ����� ��� ������� ��������*/
					else {
						node->parent->right->IsRed = 1;
						clearNode(node);
					}
				}
			}
		}
	}
}

void clearNode(Node* node) {
	if (node->parent != nullptr)
		if (node == node->parent->left)
			node->parent->left = nullptr;
		else
			node->parent->right = nullptr;

	delete node;	
}

void printInorder(Node* root) {
	
	if (root == nullptr) return;

	printInorder(root->left);

	cout << "Key: " << root->key << ", Color: " << (root->IsRed ? "RED" : "BLACK")
		 << ", Parent: " << (root -> parent ? root -> parent -> key : 0) << endl;

	printInorder(root->right);
}

void left_rotate(Node*& root,int key) { //����� �������

	Node* node = root;

	while (true) {

		if (node == nullptr) {
			cout << "��� ���� � ����� ������!";
			return;
		}

		else if (key < node->key)
			node = node->left;

		else if (key > node->key)
			node = node->right;

		else
			break;
	}

	Node* nodetmp = node->right; //������������� y

	node->right = nodetmp->left; //����� ��������� y ���������� ������ ���������� x

	if (nodetmp->left != nullptr)
		nodetmp->left->parent = node;

	nodetmp->parent = node->parent; //����� �������� Y

	if (node -> parent == nullptr)    //����� ������� � �������� ����
		root = nodetmp;
	else if (node == node->parent->left)
		node->parent->left = nodetmp;
	else
		node->parent->right = nodetmp;

	nodetmp->left = node; //����� ������ ������� Y

	node->parent = nodetmp;
}

void right_rotate(Node*& root, int key) {

	Node* node = root;

	while (true) {

		if (node == nullptr) {
			cout << "��� ���� � ����� ������!";
			return;
		}
		else if (key < node->key)
			node = node->left;
		else if (key > node->key)
			node = node->right;
		else
			break;
	}

	Node* nodetmp = node->left; //������������� Y

	node->left = nodetmp->right; //������ ��������� Y ���������� ����� ���������� x

	if (nodetmp->right != nullptr)
		nodetmp->right->parent = node;

	nodetmp->parent = node->parent; //����� �������� Y

	if (node->parent == nullptr)    //����� ������� � �������� ����
		root = nodetmp;
	else if (node == node->parent->left)
		node->parent->left = nodetmp;
	else
		node->parent->right = nodetmp;

	nodetmp->right = node; //����� ������ ������� Y

	node->parent = nodetmp;
}

/*������� ������ ������� � �������� ������, � �������� ������*/
Node* find(Node* root, int key) {

	while (true) {
		if (root == nullptr) {
			cout << "��� ���� � ����� ������!\n";
			return nullptr;
		}
		else if (key < root->key)
			root = root->left;
		else if (key > root->key)
			root = root->right;
		else
			return root;
	}
}
/*����� ���� � ������������ ������ � ������*/
int find_max(Node* root) {
	while (root -> right != nullptr)
		root = root->right;
	
	return root->key;
}

/*����� ���� � ����������� ������ � ������*/
int find_min(Node* root) {
	while (root -> left != nullptr)
		root = root->left;

	return root->key;
}
/*������� ������� ��������� ������� � ���������� ��� ����*/
int find_nearest_max(Node* root,int key) {

	while (true) {
		if (root == nullptr) {
			cout << "��� ���� � ����� ������!";
			return 0;
		}
		else if (key < root->key)
			root = root->left;
		else if (key > root->key)
			root = root->right;
		else
			break;
	}

	if (root->right != nullptr) {
		root = root->right;
		while (root->left != nullptr)
			root = root->left;
		return root->key;
	}
	else {
		cout << "���� �������� ������������";
		return key;
	}
}
/*������� ������� ��������� ������� � ���������� ��� ����*/
int find_nearest_min(Node* root, int key) {

	while (true) {
		if (root == nullptr) {
			cout << "��� ���� � ����� ������!";
			return 0;
		}
		else if (key < root->key)
			root = root->left;
		else if (key > root->key)
			root = root->right;
		else
			break;
	}

	if (root->left != nullptr) {
		root = root->left;
		while (root->right != nullptr)
			root = root->right;
		return root->key;
	}
	else {
		cout << "���� �������� �����������";
		return key;
	}
}