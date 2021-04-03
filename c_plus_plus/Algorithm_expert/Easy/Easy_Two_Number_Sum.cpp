#include <vector>
using namespace std;

vector<int> twoNumberSum(vector<int> array, int targetSum) {
  // Write your code here.
	#if 0
	unordered_map<int, int> map;
	vector<int> result;
	for (int n : array) {
		if (map.find(targetSum - n) != map.end()) {
			result.push_back(targetSum - n);
			result.push_back(n);
			map[targetSum - n]--;
			if (map[targetSum - n] == 0)
				map.erase(targetSum - n);
		} else {
			map[n]++;
		}
	}
  return result;
	#endif
	
	#if 1
	sort(array.begin(), array.end(), [](int a, int b){return a < b;});
	vector<int> result;
	int left = 0, right = array.size() - 1;
	while (left < right) {
		if (array[left] + array[right] < targetSum)
			left++;
		else if (array[left] + array[right] > targetSum)
			right--;
		else {
			result.push_back(array[left++]);
			result.push_back(array[right--]);
		}
	}
	return result;
	#endif
}

