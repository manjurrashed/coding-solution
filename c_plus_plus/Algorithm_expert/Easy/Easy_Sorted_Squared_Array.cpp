#include <vector>
using namespace std;

vector<int> sortedSquaredArray(vector<int> array) {
  // Write your code here.
	#if 0
	vector<int> result(array.size());
	for (int i = 0; i < array.size(); i++) {
		result[i] = (array[i] * array[i]);
	}
	sort(result.begin(), result.end(), [](int a, int b) {return a < b;});
  return result;
	#endif
	
	#if 1
	int left = 0; 
	int right = array.size() - 1;
	vector<int> result(array.size());
	int idx = array.size() - 1;
	while (left <= right) {
		int l = array[left] * array[left];
		int r = array[right] * array[right];
		if (l > r) {
			result[idx--] = l;
			left++;
		} else {
			result[idx--] = r;
			right--;
		}
	}
	return result;

	#endif
}

