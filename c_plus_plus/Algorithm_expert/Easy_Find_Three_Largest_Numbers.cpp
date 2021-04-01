#include <vector>
using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
  // Write your code here.
	vector<int> result(3, INT_MIN);
	for (auto n : array) {
		if (n > result[2]) {
			result[0] = result[1];
			result[1] = result[2];
			result[2] = n;
		}	else if (n > result[1] && n <= result[2]) {
			result[0] = result[1];
			result[1] = n;
		} else if (n > result[0] && n <= result[1]) {
			result[0] = n;
		}
	}
  return result;
}

