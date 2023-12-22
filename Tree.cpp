#include "Tree.h"

// Êîíñòðóêòîð ïî óìîë÷àíèþ
Tree::Tree()
{
	this->root = nullptr;
	this->high = 0;
}

// Êîíñòðóêòîð ñ ïàðàìåòðàìè
Tree::Tree(double data)
{
	Node* root = new Node{ data, nullptr, nullptr };
	this->root = root;
	this->high = 1;
}

// Êîíñòðóêòîð êîïèðîâàíèÿ
Tree::Tree(const Tree& tree)
{
	// Åñëè ïåðåäàííîå äåðåâî ïóñòîå, äåëàåì íàøå äåðåâî ïóñòûì
	if (tree.root == nullptr)
	{
		this->root = nullptr;
		this->high = 0;
	}
	// Èíà÷å êîïèðóåì äàííûå è óêàçàòåëè èç êîðíÿ ïåðåäàííîãî äåðåâà, è äåëàåì îáõîä äåðåâà â øèðèíó, ñ ïåðåäà÷åé äàííûõ è óêàçàòåëåé
	else
	{
		this->high = tree.high;
		Node* to_copy = new Node{ tree.root->data, tree.root->right, tree.root->left };
		this->root = to_copy;
		std::queue<Node*> q;
		int size = 0;
		q.push(this->root);
		// Ïîêà î÷åðåäü íå ïóñòàÿ ìû áóäåì îáðàáàòûâàòü åå ýëåìåíòû
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				Node* current = q.front();
				q.pop();
				// Åñëè ñëåâà èëè ñïðàâà åñòü ýëåìåíòû, êîïèðóåì èç íèõ çíà÷åíèÿ è óêàçàòåëè íà äðóãèå ýëåìåíòû. Òî ÷òî íàõîäèòñÿ ñëåâà è ñïðàâà çàíîñèì â î÷åðåäü
				if (current->left != nullptr) {
					// Ñêîïèðîâàëè çíà÷åíèå
					Node* to_copy = new Node{ current->left->data, current->left->right, current->left->left };
					// Ëåâûé îò òåêóùåãî ïðèðàâíÿëè ê êîïèè
					current->left = to_copy;
					// È çàíåñëè â î÷åðåäü
					q.push(current->left);
				}
				// Àíàëîãè÷íî âûøåîïèñàííîìó ñëó÷àþ
				if (current->right != nullptr) {
					Node* to_copy = new Node{ current->right->data, current->right->right, current->right->left };
					current->right = to_copy;
					q.push(current->right);
				}
			}
		}
	}
}

// Äåñòðóêòîð
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
				// Åñëè ñëåâà èëè ñïðàâà åñòü ýëåìåíòû çàíîñèì èõ â î÷åðåäü
				if (current->left != nullptr) q.push(current->left);
				if (current->right != nullptr) q.push(current->right);
				// Îáíóëÿåì óêàçàòåëè ýëåìåíòà è óäàëÿåì åãî
				current->left = nullptr;
				current->right = nullptr;
				delete current;
			}
		}
	}
}

// Ïåðåãðóçêà îïåðàòîðà ïðèñâàèâàíèÿ
Tree& Tree::operator=(const Tree& tree)
{
	int size = 0;
	std::queue<Node*> q;
	// Î÷èùàåì èñõîäíîå äåðåâî. Èñïîëüçóåì êîä èç äåñòðóêòîðà
	if (this->root != nullptr)
	{
		q.push(this->root);
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				Node* current = q.front();
				q.pop();
				// Åñëè ñëåâà èëè ñïðàâà åñòü ýëåìåíòû çàíîñèì èõ â î÷åðåäü
				if (current->left != nullptr) q.push(current->left);
				if (current->right != nullptr) q.push(current->right);
				// Îáíóëÿåì óêàçàòåëè ýëåìåíòà è óäàëÿåì åãî
				current->left = nullptr;
				current->right = nullptr;
				delete current;
			}
		}
	}
	// Êîïèðóåì ýëåìåíòû èç ïåðåäàííîãî äåðåâà
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
		// Ïîêà î÷åðåäü íå ïóñòàÿ ìû áóäåì îáðàáàòûâàòü åå ýëåìåíòû
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				Node* current = q.front();
				q.pop();
				// Åñëè ñëåâà èëè ñïðàâà åñòü ýëåìåíòû, êîïèðóåì èç íèõ çíà÷åíèÿ è óêàçàòåëè íà äðóãèå ýëåìåíòû. Òî ÷òî íàõîäèòñÿ ñëåâà è ñïðàâà çàíîñèì â î÷åðåäü
				if (current->left != nullptr) {
					// Ñêîïèðîâàëè çíà÷åíèå
					Node* to_copy = new Node{ current->left->data, current->left->right, current->left->left };
					// Ëåâûé îò òåêóùåãî ïðèðàâíÿëè ê êîïèè
					current->left = to_copy;
					// È çàíåñëè â î÷åðåäü
					q.push(current->left);
				}
				// Àíàëîãè÷íî âûøåîïèñàííîìó ñëó÷àþ
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

// Ðàñïå÷àòêà äåðåâà, ñ èñïîëüçîâàíèåì îáõîäà â ãëóáèíó
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

// Ðåêóðñèâíûé ïîèñê âûñîòû äåðåâà, ñ èñïîëüçîâàíèåì îáõîäà â ãëóáèíó
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

// Ðåêóðñèâíîå äîáàâëåíèå ýëåìåíòîâ â âåêòîð
void Tree::DFS_BYPASS(Node* root, std::vector<double>* arr)
{
	// Èäåì âñå âðåìÿ ïî ëåâîìó óêàçàòåëþ
	if (root->left != nullptr)
	{
		DFS_BYPASS(root->left, arr);
	}
	// Èäåì âñå âðåìÿ ïî ïðàâîìó óêàçàòåëþ
	if (root->right != nullptr)
	{
		DFS_BYPASS(root->right, arr);
	}
	// Äîáàâëÿåì ýëåìåíò â âåêòîð
	arr->push_back(root->data);
}



// Ïîëó÷åíèå âûñîòû äåðåâà
int Tree::get_high()
{
	return this->high;
}

// Ïîëó÷åíèå ìèíèìàëüíîãî ýëåìåíòà
double Tree::get_min()
{
	// Åñëè äåðåâî ïóñòîå ïå÷àòàåì ýòî
	if (this->root == nullptr)
	{
		std::cout << "Tree is empty" << std::endl;
		return 0.0;
	}
	// Èíà÷å ñîçäàåì óêàçàòåëü íà êîðåíü è èäåì ïî ëåâîìó óêàçàòåëþ ïîêà íå âñòðåòèì nullptr
	Node* current = this->root;
	while (current->left != nullptr)
	{
		current = current->left;
	}
	// Ìû äîøëè äî ìèíèìàëüíîãî ýëåìåíòà. Âîçâðàùàåì åãî çíà÷åíèå
	return current->data;
}

// Ïîëó÷åíèå ìàêñèìàëüíîãî ýëåìåíòà
double Tree::get_max()
{
	// Åñëè äåðåâî ïóñòîå ïå÷àòàåì ýòî
	if (this->root == nullptr)
	{
		std::cout << "Tree is empty" << std::endl;
		return 0.0;
	}
	// Èíà÷å ñîçäàåì óêàçàòåëü íà êîðåíü è èäåì ïî ïðàâîìó óêàçàòåëþ ïîêà íå âñòðåòèì nullptr
	Node* current = this->root;
	while (current->right != nullptr)
	{
		current = current->right;
	}
	// Ìû äîøëè äî ìàêñèìàëüíîãî ýëåìåíòà. Âîçâðàùàåì åãî çíà÷åíèå
	return current->data;
}

// Ïîèñê ýëåìåíòà
bool Tree::find(double data)
{
	// Åñëè äåðåâî ïóñòîå ïå÷àòàåì ýòî
	if (this->root == nullptr)
	{
		std::cout << "Tree is empty" << std::endl;
		return false;
	}
	// Èíà÷å ñîçäàåì óêàçàòåëü íà êîðåíü è èäåì â ïîçèöèþ, ãäå äîëæåí íàõîäèòüñÿ ýëåìåíò.
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
		// Åñëè íàì íóæíî ïðîéòè äàëüøå ïî äåðåâó, íî ìû âñòðåòèëè nullptr, çíà÷èò ýëåìåíòà íåò
		else if ((data < current->data) && (current->left == nullptr))
		{
			return false;
		}
		else if ((data > current->data) && (current->right == nullptr))
		{
			return false;
		}
		// Åñëè ìû äîøëè äî ïîçèöèè è îáíàðóæèëè ýëåìåíò, çíà÷èò îí åñòü
		else if (data == current->data)
		{
			return true;
		}
	}
}

// Ðåêóðñèâíûé îáõîä â ãëóáèíó
// Ïðåäñòàâëÿåò ñîáîé âåêòîð, ýëåìåíòû êîòîðîãî ðàñïîëîæåíû â ïîðÿäêå îáõîäà
std::vector<double> Tree::DFS()
{
	if (this->root != nullptr)
	{
		// Ñîçäàåì âåêòîð ÷èñåë
		std::vector<double> arr;
		// Ïðèìåíÿåì ðåêóðñèâíûé îáõîä äëÿ çàïîëíåíèÿ âåêòîðà
		DFS_BYPASS(this->root, &arr);
		return arr;
	}
	else
	{
		std::cout << "Tree is empty" << std::endl;
	}
}

// Îáõîä â øèðèíó
// Ïðåäñòàâëÿåò ñîáîé âåêòîð, ýëåìåíòû êîòîðîãî ðàñïîëîæåíû â ïîðÿäêå îáõîäà
std::vector<double> Tree::BFS()
{
	if (this->root != nullptr)
	{
		// Ñîçäàåì âåêòîð ÷èñåë
		std::vector<double> arr;
		std::queue<Node*> q;
		int size = 0;
		q.push(this->root);
		arr.push_back(this->root->data);
		// Ïîêà î÷åðåäü íå ïóñòàÿ ìû áóäåì îáðàáàòûâàòü åå ýëåìåíòû
		while (!q.empty()) {
			size = q.size();
			for (int i = 0; i < size; i++) {
				Node* current = q.front();
				q.pop();
				// Åñëè ñëåâà èëè ñïðàâà åñòü ýëåìåíòû, çàíîñèì èõ çíà÷åíèÿ â âåêòîð. Òî ÷òî ñëåâà è ñïðàâà çàíîñèì â î÷åðåäü
				if (current->left != nullptr) {
					arr.push_back(current->left->data);
					// È çàíåñëè â î÷åðåäü
					q.push(current->left);
				}
				// Àíàëîãè÷íî âûøåîïèñàííîìó ñëó÷àþ
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

// Âñòàâêà ýëåìåíòà â äåðåâî
void Tree::insert(double data)
{
	// Åñëè äåðåâî ïóñòîå, ñîçäàåì êîðåíü
	if (this->root == nullptr)
	{
		Node* to_ins = new Node{ data, nullptr, nullptr };
		this->root = to_ins;
		this->high = 1;
	}
	// Èíà÷å áåñêîíå÷íûì öèêëîì èäåì äî ïîçèöèè, íà êîòîðóþ íóæíî âñòàâèòü ýëåìåíò
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
				// Åñëè ïîçèöèÿ ýëåìåíòà ñïðàâà, íî òàì íè÷åãî íåò, òóäà è âñòàâëÿåì ýëåìåíò 
				Node* to_ins = new Node{ data, nullptr, nullptr };
				current->right = to_ins;
				break;
			}
			else if ((data < current->data) && (current->left == nullptr))
			{
				// Àíàëîãè÷íî âûøåîïèñàííîìó ñëó÷àþ
				Node* to_ins = new Node{ data, nullptr, nullptr };
				current->left = to_ins;
				break;
			}
		}
		// Ðåêóðñèâíî ïåðåñ÷èòûâàåì âûñîòó äåðåâà
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
				std::cout << "Ýëåìåíòà íåò â äåðåâå: " << data << std::endl;
				break;
			}
			else if ((data > current->data) && (current->right == nullptr))
			{
				std::cout << "Ýëåìåíòà íåò â äåðåâå: " << data << std::endl;
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

void Tree::buildTreeFromList(Node* head) {
        if (!head)
            return;

        root = new Node(head->data);
        Node* current = head->next;

        while (current) {
            insert(current->data);
            current = current->next;
        }
    }


