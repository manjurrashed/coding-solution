#include <vector>

using namespace std;

vector<int> moveElementToEnd(vector<int> array, int toMove) {
  // Write your code here.
	#if 0
	int idx = array.size() - 1;
	for (int i = array.size() - 1; i > -1; i--) {
		if (array[i] == toMove)
			swap(array[i], array[idx--]);
	}
	return array;
	#endif
	#if 1
	int idx = array.size() - 1;
	int i = 0;
	while (i < idx) {
		if (array[idx] == toMove) {
			idx--;
			continue;
		}
		if (array[i] == toMove)
			swap(array[i], array[idx--]);
		i++;
	}
	return array;
	#endif
}

