#pragma once
#include <iostream>
#include <queue>

class Tree
{
public:
	// Структура узла дерева.
	struct Node
	{
		double data;
		Node* right;
		Node* left;
		Node(double value, Node* right = nullptr, Node* left = nullptr) : data(value), right(right), left(left) {}
	};
	
private:
	int high; // Высота дерева
	int max(int a, int b);
	void print1(Node* root, int space, int height); // Распечатка дерева, с использованием обхода в глубину
	int high1(Node* root); // Рекурсивный поиск высоты дерева, с использованием обхода в глубину
	void DFS_BYPASS(Node* root, std::vector<double>* arr); // Рекурсивное добавление элементов в вектор

public:
	Node* root; // Указатель на первый элемент дерева
	Node* newroot;
	Tree(); // Конструктор по умолчанию
	Tree(double data); // Конструктор с параметрами
	Tree(const Tree& tree); // Конструктор копирования
	~Tree(); // Деструктор
	Tree& operator=(const Tree& tree); // Перегрузка оператора присваивания
	int get_high(); // Получение высоты дерева
	double get_min(); // Получение минимального элемента
	double get_max(); // Получение максимального элемента
	bool find(double data); // Поиск элемента
	std::vector<double> DFS(); // Рекурсивный обход в глубину
	std::vector<double> BFS(); // Обход в ширину
	void print(); // Отрисовка дерева на эране
	void insert(double data); // Вставка элемента в дерево
	void remove(double data); // Удаление элемента дерева
	//Tree More(Node* leaf, int value);
	//Node* extractSubtree(Node* root, int threshold);
	//void printMore(Node* leaf, int value, int level);
	Node* extractSubtree(Node* root, double threshold);
};
// мне нужно создать метод который будет искать элемент и брать от него дерево которое больше этого числа и выводить на экран 