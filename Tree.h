#pragma once
#include <iostream>
#include <queue>

class Tree
{
public:
	// ��������� ���� ������.
	struct Node
	{
		double data;
		Node* right;
		Node* left;
		Node(double value, Node* right = nullptr, Node* left = nullptr) : data(value), right(right), left(left) {}
	};
	
private:
	int high; // ������ ������
	int max(int a, int b);
	void print1(Node* root, int space, int height); // ���������� ������, � �������������� ������ � �������
	int high1(Node* root); // ����������� ����� ������ ������, � �������������� ������ � �������
	void DFS_BYPASS(Node* root, std::vector<double>* arr); // ����������� ���������� ��������� � ������

public:
	Node* root; // ��������� �� ������ ������� ������
	Node* newroot;
	Tree(); // ����������� �� ���������
	Tree(double data); // ����������� � �����������
	Tree(const Tree& tree); // ����������� �����������
	~Tree(); // ����������
	Tree& operator=(const Tree& tree); // ���������� ��������� ������������
	int get_high(); // ��������� ������ ������
	double get_min(); // ��������� ������������ ��������
	double get_max(); // ��������� ������������� ��������
	bool find(double data); // ����� ��������
	std::vector<double> DFS(); // ����������� ����� � �������
	std::vector<double> BFS(); // ����� � ������
	void print(); // ��������� ������ �� �����
	void insert(double data); // ������� �������� � ������
	void remove(double data); // �������� �������� ������
	//Tree More(Node* leaf, int value);
	//Node* extractSubtree(Node* root, int threshold);
	//void printMore(Node* leaf, int value, int level);
	Node* extractSubtree(Node* root, double threshold);
};
// ��� ����� ������� ����� ������� ����� ������ ������� � ����� �� ���� ������ ������� ������ ����� ����� � �������� �� ����� 