#include "Tree.h"

// Конструктор по умолчанию
Tree::Tree()
{
	this->root = nullptr;
	this->high = 0;
}

// Конструктор с параметрами
Tree::Tree(double data)
{
	Node* root = new Node{ data, nullptr, nullptr };
	this->root = root;
	this->high = 1;
}

// Конструктор копирования
Tree::Tree(const Tree& tree)
{
	// Если переданное дерево пустое, делаем наше дерево пустым
	if (tree.root == nullptr)
	{
		this->root = nullptr;
		this->high = 0;
	}
	// Иначе копируем данные и указатели из корня переданного дерева, и делаем обход дерева в ширину, с передачей данных и указателей
	else
	{
		this->high = tree.high;
		Node* to_copy = new Node{ tree.root->data, tree.root->right, tree.root->left };
		this->root = to_copy;
		std::queue<Node*> q;
		int size = 0;
		q.push(this->root);
		// Пока очередь не пустая мы будем обрабатывать ее элементы
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				Node* current = q.front();
				q.pop();
				// Если слева или справа есть элементы, копируем из них значения и указатели на другие элементы. То что находится слева и справа заносим в очередь
				if (current->left != nullptr) {
					// Скопировали значение
					Node* to_copy = new Node{ current->left->data, current->left->right, current->left->left };
					// Левый от текущего приравняли к копии
					current->left = to_copy;
					// И занесли в очередь
					q.push(current->left);
				}
				// Аналогично вышеописанному случаю
				if (current->right != nullptr) {
					Node* to_copy = new Node{ current->right->data, current->right->right, current->right->left };
					current->right = to_copy;
					q.push(current->right);
				}
			}
		}
	}
}

// Деструктор
Tree::~Tree()
{
	if (this->root != nullptr)
	{
		std::queue<Node*> q;
		int size = 0;
		q.push(this->root);
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				Node* current = q.front();
				q.pop();
				// Если слева или справа есть элементы заносим их в очередь
				if (current->left != nullptr) q.push(current->left);
				if (current->right != nullptr) q.push(current->right);
				// Обнуляем указатели элемента и удаляем его
				current->left = nullptr;
				current->right = nullptr;
				delete current;
			}
		}
	}
}

// Перегрузка оператора присваивания
Tree& Tree::operator=(const Tree& tree)
{
	int size = 0;
	std::queue<Node*> q;
	// Очищаем исходное дерево. Используем код из деструктора
	if (this->root != nullptr)
	{
		q.push(this->root);
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				Node* current = q.front();
				q.pop();
				// Если слева или справа есть элементы заносим их в очередь
				if (current->left != nullptr) q.push(current->left);
				if (current->right != nullptr) q.push(current->right);
				// Обнуляем указатели элемента и удаляем его
				current->left = nullptr;
				current->right = nullptr;
				delete current;
			}
		}
	}
	// Копируем элементы из переданного дерева
	if (tree.root == nullptr)
	{
		this->root = nullptr;
		this->high = 0;
	}
	else
	{
		this->high = tree.high;
		Node* to_copy = new Node{ tree.root->data, tree.root->right, tree.root->left };
		this->root = to_copy;
		q.push(this->root);
		// Пока очередь не пустая мы будем обрабатывать ее элементы
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				Node* current = q.front();
				q.pop();
				// Если слева или справа есть элементы, копируем из них значения и указатели на другие элементы. То что находится слева и справа заносим в очередь
				if (current->left != nullptr) {
					// Скопировали значение
					Node* to_copy = new Node{ current->left->data, current->left->right, current->left->left };
					// Левый от текущего приравняли к копии
					current->left = to_copy;
					// И занесли в очередь
					q.push(current->left);
				}
				// Аналогично вышеописанному случаю
				if (current->right != nullptr) {
					Node* to_copy = new Node{ current->right->data, current->right->right, current->right->left };
					current->right = to_copy;
					q.push(current->right);
				}
			}
		}
	}
	return *this;
}
int Tree::max(int a, int b)
{
	if (a >= b) return a;
	else return b;
}

// Распечатка дерева, с использованием обхода в глубину
void Tree::print1(Node* root, int space = 0, int height = 10)
{
	if (root == nullptr) return;
	space += height;
	print1(root->right, space);
	std::cout << std::endl;
	for (int i = height; i < space; i++) {
		std::cout << " ";
	}
	std::cout << root->data << "\n";
	print1(root->left, space);
}

// Рекурсивный поиск высоты дерева, с использованием обхода в глубину
int Tree::high1(Node* root)
{
	if (root == nullptr)
	{
		return 0;
	}
	else
	{
		return 1 + max(high1(root->left), high1(root->right));
	}
}

// Рекурсивное добавление элементов в вектор
void Tree::DFS_BYPASS(Node* root, std::vector<double>* arr)
{
	// Идем все время по левому указателю
	if (root->left != nullptr)
	{
		DFS_BYPASS(root->left, arr);
	}
	// Идем все время по правому указателю
	if (root->right != nullptr)
	{
		DFS_BYPASS(root->right, arr);
	}
	// Добавляем элемент в вектор
	arr->push_back(root->data);
}



// Получение высоты дерева
int Tree::get_high()
{
	return this->high;
}

// Получение минимального элемента
double Tree::get_min()
{
	// Если дерево пустое печатаем это
	if (this->root == nullptr)
	{
		std::cout << "Tree is empty" << std::endl;
		return 0.0;
	}
	// Иначе создаем указатель на корень и идем по левому указателю пока не встретим nullptr
	Node* current = this->root;
	while (current->left != nullptr)
	{
		current = current->left;
	}
	// Мы дошли до минимального элемента. Возвращаем его значение
	return current->data;
}

// Получение максимального элемента
double Tree::get_max()
{
	// Если дерево пустое печатаем это
	if (this->root == nullptr)
	{
		std::cout << "Tree is empty" << std::endl;
		return 0.0;
	}
	// Иначе создаем указатель на корень и идем по правому указателю пока не встретим nullptr
	Node* current = this->root;
	while (current->right != nullptr)
	{
		current = current->right;
	}
	// Мы дошли до максимального элемента. Возвращаем его значение
	return current->data;
}

// Поиск элемента
bool Tree::find(double data)
{
	// Если дерево пустое печатаем это
	if (this->root == nullptr)
	{
		std::cout << "Tree is empty" << std::endl;
		return false;
	}
	// Иначе создаем указатель на корень и идем в позицию, где должен находиться элемент.
	Node* current = this->root;
	while (true)
	{
		if ((data > current->data) && (current->right != nullptr))
		{
			current = current->right;
		}
		else if ((data < current->data) && (current->left != nullptr))
		{
			current = current->left;
		}
		// Если нам нужно пройти дальше по дереву, но мы встретили nullptr, значит элемента нет
		else if ((data < current->data) && (current->left == nullptr))
		{
			return false;
		}
		else if ((data > current->data) && (current->right == nullptr))
		{
			return false;
		}
		// Если мы дошли до позиции и обнаружили элемент, значит он есть
		else if (data == current->data)
		{
			return true;
		}
	}
}

// Рекурсивный обход в глубину
// Представляет собой вектор, элементы которого расположены в порядке обхода
std::vector<double> Tree::DFS()
{
	if (this->root != nullptr)
	{
		// Создаем вектор чисел
		std::vector<double> arr;
		// Применяем рекурсивный обход для заполнения вектора
		DFS_BYPASS(this->root, &arr);
		return arr;
	}
	else
	{
		std::cout << "Tree is empty" << std::endl;
	}
}

// Обход в ширину
// Представляет собой вектор, элементы которого расположены в порядке обхода
std::vector<double> Tree::BFS()
{
	if (this->root != nullptr)
	{
		// Создаем вектор чисел
		std::vector<double> arr;
		std::queue<Node*> q;
		int size = 0;
		q.push(this->root);
		arr.push_back(this->root->data);
		// Пока очередь не пустая мы будем обрабатывать ее элементы
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				Node* current = q.front();
				q.pop();
				// Если слева или справа есть элементы, заносим их значения в вектор. То что слева и справа заносим в очередь
				if (current->left != nullptr) {
					arr.push_back(current->left->data);
					// И занесли в очередь
					q.push(current->left);
				}
				// Аналогично вышеописанному случаю
				if (current->right != nullptr) {
					arr.push_back(current->right->data);
					q.push(current->right);
				}
			}
		}
		return arr;
	}
	else
	{
		std::cout << "Tree is empty" << std::endl;
	}
}

void Tree::print()
{
	if (this->root == nullptr)
	{
		std::cout << "Tree is empty" << std::endl;
	}
	else
	{
		print1(this->root);
	}
}

// Вставка элемента в дерево
void Tree::insert(double data)
{
	// Если дерево пустое, создаем корень
	if (this->root == nullptr)
	{
		Node* to_ins = new Node{ data, nullptr, nullptr };
		this->root = to_ins;
		this->high = 1;
	}
	// Иначе бесконечным циклом идем до позиции, на которую нужно вставить элемент
	else
	{
		Node* current = this->root;
		while (true)
		{
			if ((data >= current->data) && (current->right != nullptr))
			{
				current = current->right;
			}
			else if ((data < current->data) && (current->left != nullptr))
			{
				current = current->left;
			}
			else if ((data >= current->data) && (current->right == nullptr))
			{
				// Если позиция элемента справа, но там ничего нет, туда и вставляем элемент 
				Node* to_ins = new Node{ data, nullptr, nullptr };
				current->right = to_ins;
				break;
			}
			else if ((data < current->data) && (current->left == nullptr))
			{
				// Аналогично вышеописанному случаю
				Node* to_ins = new Node{ data, nullptr, nullptr };
				current->left = to_ins;
				break;
			}
		}
		// Рекурсивно пересчитываем высоту дерева
		this->high = high1(this->root);
	}
}

void Tree::remove(double data)
{
	if (this->root == nullptr)
	{
		std::cout << "Tree is empty" << std::endl;
	}
	else if (this->root->data == data)
	{
		if ((this->root->left == nullptr) && (root->right == nullptr))
		{
			Node* to_del = this->root;
			delete to_del;
		}
		else if ((this->root->left != nullptr) && (root->right == nullptr))
		{
			Node* to_del = this->root;
			this->root = this->root->left;
			delete to_del;
		}
		else if ((this->root->left == nullptr) && (root->right != nullptr))
		{
			Node* to_del = this->root;
			this->root = this->root->right;
			delete to_del;
		}
		else
		{
			Node* to_del = this->root;
			this->root = this->root->right;
			this->root->left = to_del->left;
			delete to_del;
		}
	}
	else
	{
		Node* current = this->root;
		while (true)
		{
			if ((data >= current->data) && (current->right != nullptr))
			{
				if (current->right->data == data)
				{
					if ((current->right->left == nullptr) && (current->right->right == nullptr))
					{
						Node* to_del = current->right;
						delete to_del;
						current->right = nullptr;
						break;
					}
					else if ((current->right->left != nullptr) && (current->right->right == nullptr))
					{
						Node* to_del = current->right;
						current->right = current->right->left;
						delete to_del;
						break;
					}
					else if ((current->right->left == nullptr) && (current->right->right != nullptr))
					{
						Node* to_del = current->right;
						current->right = current->right->right;
						delete to_del;
						break;
					}
					else
					{
						Node* to_del = current->right;
						current->right = current->right->right;
						current->right->left = to_del->left;
						delete to_del;
						break;
					}
				}
				else
				{
					current = current->right;
				}
			}
			else if ((data < current->data) && (current->left != nullptr))
			{
				if (current->left->data == data)
				{
					if ((current->left->left == nullptr) && (current->left->right == nullptr))
					{
						Node* to_del = current->left;
						delete to_del;
						current->left = nullptr;
						break;
					}
					else if ((current->left->left != nullptr) && (current->left->right == nullptr))
					{
						Node* to_del = current->left;
						current->left = current->left->left;
						delete to_del;
						break;
					}
					else if ((current->left->left == nullptr) && (current->left->right != nullptr))
					{
						Node* to_del = current->left;
						current->left = current->left->right;
						delete to_del;
						break;
					}
					else
					{
						Node* to_del = current->left;
						current->left = current->left->right;
						current->left->left = to_del->left;
						delete to_del;
						break;
					}
				}
				else
				{
					current = current->left;
				}
			}
			else if ((data < current->data) && (current->left == nullptr))
			{
				std::cout << "Элемента нет в дереве: " << data << std::endl;
				break;
			}
			else if ((data > current->data) && (current->right == nullptr))
			{
				std::cout << "Элемента нет в дереве: " << data << std::endl;
				break;
			}
		}
	}
	this->high = high1(this->root);
}
Tree::Node* Tree::extractSubtree(Node* root, double threshold)
{
	if (root == nullptr)
		return nullptr;

	root->left = extractSubtree(root->left, threshold);
	root->right = extractSubtree(root->right, threshold);

	if (root->data > threshold)
	{
		Node* newRoot = new Node(root->data);

		newRoot->left = root->left ? new Node(root->left->data) : nullptr;
		newRoot->right = root->right ? new Node(root->right->data) : nullptr;

		std::cout << "Creating new node with data: " << newRoot->data << std::endl;

		return newRoot;
	}

	Node* result = nullptr;

	if (root->left && root->left->data > threshold)
		result = root->left;
	else if (root->right && root->right->data > threshold)
		result = root->right;

	std::cout << "Removing node with data: " << root->data << std::endl;
	delete root;

	return result;
}



