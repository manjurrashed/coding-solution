#include <vector>
using namespace std;

int kadanesAlgorithm(vector<int> array) {
  // Write your code here.
	#if 0
	int max_val = INT_MIN;
	int sum = 0;
	for (auto n : array) {
		sum = max(n, sum + n);
		max_val = max(max_val, sum);
	}
  return max_val;
	#endif
	#if 0
	int max_val = INT_MIN;
	for (int i = 0; i < array.size(); i++) {
		for (int j = i; j < array.size(); j++) {
			int sum = 0;
			for (int k = i; k <= j; k++) {
				sum += array[k];
			}
			max_val = max(max_val, sum);
		}
	}
	return max_val;
	#endif
	#if 1
	vector<int> sum(array.size() + 1, 0);
	sum[0] = 0;
	for (int i = 0; i < array.size(); i++) {
		sum[i + 1] = sum[i] + array[i];
	}
	int max_val = INT_MIN;
	for (int i = 0; i < array.size(); i++) {
		for (int j = i + 1; j <= array.size(); j++) {
			max_val = max(max_val, sum[j] - sum[i]);
		}
	}
	return max_val;
	#endif
}

