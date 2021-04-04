#include <vector>
using namespace std;

void helper(vector<int> &array, int level, vector<int> &data, vector<vector<int>> &result) {
	if (array.size() == level) {
		result.push_back(data);
		return;
	}
	helper(array, level + 1, data, result);
	data.push_back(array[level]);
	helper(array, level + 1, data, result);
	data.pop_back();

}
vector<vector<int>> powerset(vector<int> array) {
  // Write your code here.
	#if 0
	//iterative
	vector<vector<int>> result = {{}};
	for (auto n : array) {
		int size = result.size();
		for (int i = 0; i < size; i++) {
			vector<int> data = result[i];
			data.push_back(n);
			result.push_back(data);
		}
	}
	return result;
	#endif
	#if 1
	//recursive
	vector<vector<int>> result;
	vector<int> data;
	helper(array, 0, data, result);
	return result;
	#endif
}

