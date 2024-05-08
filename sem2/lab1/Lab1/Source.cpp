#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace Y;
using namespace std;

Deck* Deck :: crtdeck() {
	int n; Deck* node1 = new Deck; Deck* node2 = new Deck;
	cout << "������� ���������� ��������� � ����:";
	cin >> n;
	while (cin.fail()|| n<1) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "������� ���������� ��������� � ����:";
		cin >> n;
	}
	cout << "������� �������:";
	cin >> this->val;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "������� �������:";
		cin >> this->val;
	}
	this->prev = nullptr;
	this->next = node1;
	node1->prev = this;
	for (int i = 1; i < n; i++) {
		cout << "������� �������:";
		cin >> node1->val;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "������� �������:";
			cin >> node1->val;
		}
		node2 = new Deck;
		node2->prev = node1;
		node1->next = node2;
		node1 = node2;
	}
	node2 = node1->prev;
	node2->next = nullptr;
	delete node1;
	return this;
}
void Deck::output() {
	Deck* node = this;
	if (this != nullptr&&this->val) {
		node = this;
		while (node != nullptr) {
			cout << node->val << " ";
			node = node->next;
		}
	}
	else {
		cout << "��� ����";
	}
	delete node;
	return;
}

Deck* Deck::delfront(Deck*& begin) {
	Deck* buff = nullptr; 
	if(begin->next!=nullptr)
	buff = begin->next;
	else {
		delete begin; begin = nullptr;
		return nullptr;
	}
	if ( buff!=nullptr) {
		if (buff->next != nullptr) {
			begin->val = buff->val;
			begin->next = begin->next->next;
			if (begin->next != nullptr) {
				begin->next->prev = begin;
			}
		}
		else {
			begin = buff;
			buff = begin->prev;
		}
		delete buff;

	}
	return begin;
}
Deck* Deck::delback(Deck*& end,Deck*& begin) {
	Deck* buff = end;
	if (end == begin) {
		delete end;
		end = nullptr;
		return nullptr;
	}
	else {
		end = end->prev;
		end->next = nullptr;
		delete buff;
		return begin;
	}
}
Deck* Deck::addfront(Deck*& begin) {
	Deck* node = new Deck;
		node->next = begin->next;
		node->prev = begin;
		begin->next = node;
		if (node->next != nullptr) {
			node->next->prev = node;
		}
		node->val = begin->val;
		cout << "������� ��������:";
		cin >> begin->val;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(10000, '\n');
			cout << "������� ��������:";
			cin >> begin->val;
		}
	return begin;
}
Deck* Deck::addback(Deck*& end) {
	Deck* node = new Deck; 
	node->prev = end;
	end->next = node; 
	cout << "������� ��������:";
	cin >> node->val;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(10000, '\n');
		cout << "������� ��������:";
		cin >> node->val;
	}
	node->next = nullptr;
	end = node;
	return this;
}
Deck* Y::Deck::file()
{
	std::ifstream file("tests.txt");
	if (!file) {
		std::cerr << "���� �� ������." << std::endl;
		exit(0);
	}
	std::string line;
	std::getline(file, line);
	std::istringstream iss(line);
	Y::Deck* deck = this; Deck* buff = nullptr;
	int number;
	deck->next = nullptr;
	deck->prev = nullptr;
	while (iss >> number) {
		deck->val = number;
		buff = new Deck;
		buff->prev = deck;
		deck->next = buff;
		deck = buff;
	}
	if (deck->prev != nullptr) {
		deck = deck->prev; delete buff;
		deck->next = nullptr;
	}
	return this;


}


