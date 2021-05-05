#include <vector>
using namespace std;

vector<int> smallestDifference(vector<int> arrayOne, vector<int> arrayTwo) {
  // Write your code here.
	std::sort(arrayOne.begin(), arrayOne.end());
	std::sort(arrayTwo.begin(), arrayTwo.end());
	int smallest_diff = INT_MAX;
	int one_idx = 0;
	int two_idx = 0;
	vector<int> result;
	while (one_idx < arrayOne.size() && two_idx < arrayTwo.size()) {
		int current_diff = INT_MAX;
		int n1 = arrayOne[one_idx];
		int n2 = arrayTwo[two_idx];
		if (n1 < n2) {
			current_diff = n2 - n1;
			one_idx++;
		} else if (n2 < n1) {
			current_diff = n1 - n2;
			two_idx++;
		} else {
			return {n1, n2};
		}
		if (current_diff < smallest_diff) {
			smallest_diff = current_diff;
			result = {n1, n2};
		}
	}
  return result;
}

