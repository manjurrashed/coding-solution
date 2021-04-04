#include <vector>
using namespace std;

vector<int> threeNumberSort(vector<int> array, vector<int> order) {
  // Write your code here.
	#if 0
	// same direction
	int left = 0;
	int right = array.size() - 1;
	for (int i = 0; i < array.size(); i++) {
		if (array[i] == order[0])
			swap(array[i], array[left++]);
	}
	for (int i = array.size() - 1; i > -1; i--) {
		if (array[i] == order[2])
			swap(array[i], array[right--]);
	}
  return array;
	#endif
	
	#if 1
	//opposite direction
	int idx = 0;
	int i = array.size() - 1;
	while (i >= idx) {
		if (array[idx] == order[0]) { idx++; continue; } 
		if (array[i] == order[0]) { swap(array[idx++], array[i]);}
		i--;
	}
	idx = array.size() - 1;
	i = 0;
	while (i < idx) {
		if (array[idx] == order[2]) { idx--; continue; }
		if (array[i] == order[2]) { swap(array[idx--], array[i]);}
		i++;
	}
	return array;
	#endif
}

