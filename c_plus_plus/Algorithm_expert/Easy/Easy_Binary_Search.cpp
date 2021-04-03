#include <vector>
using namespace std;

int helper(vector<int> &array, int left, int right, int target) {
	if (left > right)
		return -1;
	int mid = (left + right) / 2;
	if (array[mid] == target)
		return mid;
	else if (array[mid] < target)
		return helper(array, mid + 1, right, target);
	else 
		return helper(array, left, mid - 1, target);
}
int binarySearch(vector<int> array, int target) {
  // Write your code here.
	#if 0
	//iterative
	int left = 0;
	int right = array.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (array[mid] == target)
			return mid;
		else if (array[mid] < target)
			left = mid + 1;
		else 
			right = mid - 1;
	}
	return -1;
	#endif
	
	#if 1
	return helper(array, 0, array.size() -1, target);
	#endif
}

