#include <vector>

using namespace std;

vector<int> arrayOfProducts(vector<int> array) {
  // Write your code here.
	#if 1
	vector<int> result(array.size(), 1);
	int product = 1;
	for (int i = 0; i < array.size() - 1; i++) {
		product *= array[i];
		result[i + 1] *= product;
	}
	product = 1;
	for (int i = array.size() - 1; i > 0; i--) {
		product *= array[i];
		result[i - 1] *= product;
	}
	return result;
	#endif
}

