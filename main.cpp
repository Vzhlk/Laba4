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
	std::cout << "Ìèíèìàëüíûé ýëåìåíò: " << tree.get_min() << " " << "Ìàêñèìàëüíûé ýëåìåíò: " << tree.get_max() << std::endl;
	std::cout << "Âûñîòà äåðåâà: " << tree.get_high() << std::endl;
	std::cout << tree.find(9) << " " << tree.find(-11) << std::endl;
	tree.remove(-11);
	tree.remove(58);
	std::cout << "Âûñîòà äåðåâà ïîñëå óäàëåíèÿ ýëåìåíòîâ: " << tree.get_high() << std::endl;
	tree.print();
	std::vector<double> arr_DFS = tree.DFS();
	std::cout << "Ðåçóëüòàò îáõîäà â ãëóáèíó" << std::endl;
	for (int i = 0; i < arr_DFS.size(); i++) 
		std::cout << arr_DFS[i] << " ";
	std::cout << std::endl;
	std::cout << "Ðåçóëüòàò îáõîäà â øèðèíó" << std::endl;
	std::vector<double> arr_BFS = tree.BFS();
	for (int i = 0; i < arr_BFS.size(); i++) 
		std::cout << arr_BFS[i] << " ";
	std::cout << std::endl;
	
	std::cout << "Ïîääåðåâî áèíàðíîãî äåðåâà:" << std::endl;
//ошибки с этого момента
	Tree::Node* newRoot = tree.extractSubtree(tree.root, 15.0);
	tree.root = newRoot;
	            
	tree.print();
	delete newRoot;

	return 0;
}
