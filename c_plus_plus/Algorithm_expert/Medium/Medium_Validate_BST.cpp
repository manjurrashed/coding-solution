class BST {
public:
  int value;
  BST *left;
  BST *right;

  BST(int val);
  BST &insert(int val);
};

bool helper(BST *root, int min_val, int max_val) {
	if (root == nullptr)
		return true;
	if (root->value < min_val || root->value >= max_val)
		return false;
	
	bool left = helper(root->left, min_val, root->value);
	if (left == false)
		return false;
	return helper(root->right, root->value, max_val);
}

bool validateBst(BST *tree) {
  // Write your code here.
	return helper(tree, INT_MIN, INT_MAX);
}

