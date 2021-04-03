using namespace std;

// This is the class of the input root. Do not edit it.
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

void helper(BinaryTree *root, int sum, vector<int> &result) {
	if (root == nullptr)
		return;
	sum += root->value;
	if (root->left == nullptr && root->right == nullptr) {
		result.push_back(sum);
		return;
	}
	helper(root->left, sum, result);
	helper(root->right, sum, result);
}
vector<int> branchSums(BinaryTree *root) {
  // Write your code here.
	vector<int> result;
	helper(root, 0, result);
  return result;
}

