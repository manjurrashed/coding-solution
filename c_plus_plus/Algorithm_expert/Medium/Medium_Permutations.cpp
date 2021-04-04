#include <vector>
using namespace std;

void helper(vector<int> &array, int level, vector<vector<int>> &result) {
	if (array.size() - 1 == level) {
		result.push_back(array);
		return;
	}
	for (int i = level; i < array.size(); i++) {
		swap(array[i], array[level]);
		helper(array, level + 1, result);
		swap(array[i], array[level]);
	}
}
vector<vector<int>> getPermutations(vector<int> array) {
  // Write your code here.
	vector<vector<int>> result;
  helper(array, 0, result);
	return result;
}

