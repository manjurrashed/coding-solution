#include <vector>
using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	#if 1
	//order O(n^2) with sorting.
	vector<vector<int>> result;
	sort(array.begin(), array.end(), [](int a, int b){ return a < b; });
	for (int i = 0; i < array.size() - 2; i++) {
		int left = i + 1;
		int right = array.size() - 1;
		int target = targetSum - array[i];
		while(left < right) {
			if (array[left] + array[right] == target){
				result.push_back({array[i], array[left++], array[right--]});
			} else if (array[left] + array[right] < target){
				left++;
			} else
				right--;
		}
	}
	return result;
	#endif
	#if 0
	//O(n^2) without sorting.
	vector<vector<int>> result;
	for (int i = 0; i < array.size() - 2; i++) {
		int target = targetSum - array[i];
		unordered_map<int, int> map;
		for (int j = i + 1; j < array.size(); j++) {
			int diff = target - array[j];
			if (map.find(diff) != map.end()) {
				result.push_back({array[i], diff, array[j]});
				map[diff]--;
				if (map[diff] == 0)
					map.erase(diff);
			} else {
				map[array[j]]++;
			}
		}
	}
	return result;
	#endif
	
}

