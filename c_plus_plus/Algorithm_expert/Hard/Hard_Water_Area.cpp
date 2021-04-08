#include <vector>
using namespace std;

int waterArea(vector<int> heights) {
  // Write your code here.
	#if 0
	vector<int> water(heights.size());
	int sum = 0;
	int max_val = INT_MIN;
	for (int i = 0; i < heights.size(); i++) {
		max_val = max(max_val, heights[i]);
		water[i] = max_val;
	}
	max_val = INT_MIN;
	for (int i = heights.size() -1 ; i > -1; i--) {
		max_val = max(max_val, heights[i]);
		water[i] = min(water[i], max_val);
		sum += water[i] - heights[i];
	}
	return sum;
	#endif

	#if 1
	int sum = 0;
	int left = 0;
	int right = heights.size() - 1;
	int left_max = INT_MIN;
	int right_max = INT_MIN;
	while (left <= right) {
		left_max = max(left_max, heights[left]);
		right_max = max(right_max, heights[right]);
		if (left_max < right_max) {
			sum += left_max - heights[left++];
		} else {
			sum += right_max - heights[right--];
		}
	}
	return sum;
	#endif
}

