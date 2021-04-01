using namespace std;

class BinaryTree {
public:
  int value;
  BinaryTree *left;
  BinaryTree *right;

  BinaryTree(int value) {
    this->value = value;
    left = nullptr;
    right = nullptr;
  }
};

void helper1(BinaryTree *root, int level, int &sum) {
	if (!root)
		return;
	sum += level;
	helper1(root->left, level + 1, sum);
	helper1(root->right, level + 1, sum);
}
int helper2(BinaryTree *root, int level) {
	if (!root)
		return 0;
	return level + helper2(root->left, level + 1) + helper2(root->right, level + 1);
}
int nodeDepths(BinaryTree *root) {
  // Write your code here.
	#if 0
	int result = 0;
	helper1(root, 0, result);
	return result;
	#endif
	return helper2(root, 0);
}

