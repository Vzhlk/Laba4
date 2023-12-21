#include "Tree.h"

int main()
{
	system("color F0");
	setlocale(LC_ALL, "RUSSIAN");
	
	Tree tree(0);
	tree.insert(10.0);
	tree.insert(15.0);
	tree.insert(-3.0);
	tree.insert(7.0);
	tree.insert(-34.0);
	tree.insert(58.0);
	tree.insert(19.0);
	tree.insert(-21.0);
	tree.insert(47.0);
	if (true)
	{
		Tree tree_to_copy = tree;
		tree_to_copy.insert(45);
		tree_to_copy.insert(-87);
		tree_to_copy = tree;
	}
	tree.print();
	std::cout << "Минимальный элемент: " << tree.get_min() << " " << "Максимальный элемент: " << tree.get_max() << std::endl;
	std::cout << "Высота дерева: " << tree.get_high() << std::endl;
	std::cout << tree.find(9) << " " << tree.find(-11) << std::endl;
	tree.remove(-11);
	tree.remove(58);
	std::cout << "Высота дерева после удаления элементов: " << tree.get_high() << std::endl;
	tree.print();
	std::vector<double> arr_DFS = tree.DFS();
	std::cout << "Результат обхода в глубину" << std::endl;
	for (int i = 0; i < arr_DFS.size(); i++) 
		std::cout << arr_DFS[i] << " ";
	std::cout << std::endl;
	std::cout << "Результат обхода в ширину" << std::endl;
	std::vector<double> arr_BFS = tree.BFS();
	for (int i = 0; i < arr_BFS.size(); i++) 
		std::cout << arr_BFS[i] << " ";
	std::cout << std::endl;
	
	std::cout << "Поддерево бинарного дерева:" << std::endl;

	Tree::Node* newRoot = tree.extractSubtree(tree.root, 15.0);
	tree.root = newRoot;
	            
	tree.print();
	delete newRoot;

	return 0;
}