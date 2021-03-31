#include <vector>
using namespace std;

vector<int> insertionSort(vector<int> array) {
  // Write your code here.
	for (int i = 1; i < array.size(); i++) {
		int temp = array[i];
		int j = i - 1;
		while (j > -1 && array[j] > temp) {
			array[j + 1] = array[j];
			j--;
		}
		array[j + 1] = temp;
	}
  return array;
}

