class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

void helper(BST *tree, int target, int &diff, int &d) {
	if (tree == nullptr) return;
	
	if (diff > abs(tree->value - target)) {
		diff = abs(tree->value - target);
		d = tree->value;
	}

	if (target < tree->value)
		helper(tree->left, target, diff, d);
	else
		helper(tree->right, target, diff, d);
}
int findClosestValueInBst(BST *tree, int target) {
  // Write your code here.
	int diff = INT_MAX;
	int d;
	helper(tree, target, diff, d);
  return d;
}

