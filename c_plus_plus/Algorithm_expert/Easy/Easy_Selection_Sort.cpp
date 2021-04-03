#include <vector>
using namespace std;

vector<int> selectionSort(vector<int> array) {
  // Write your code here.
	for (int i = 0; i < array.size() - 1; i++) {
		int small_idx = i;
		for (int j = i + 1; j < array.size(); j++) {
			if (array[j] < array[small_idx])
				small_idx = j;
		}
		swap(array[i], array[small_idx]);
	}
  return array;
}

