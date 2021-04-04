#include <vector>
using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value);
  void insert(vector<int> values, int i = 0);
  void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
  // Write your code here.
	#if 0
	if (!tree) return;
	swap(tree->left, tree->right);
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);
	#endif
	#if 1
	if (!tree) return;
	invertBinaryTree(tree->left);
	invertBinaryTree(tree->right);
	swap(tree->left, tree->right);
	#endif
}

