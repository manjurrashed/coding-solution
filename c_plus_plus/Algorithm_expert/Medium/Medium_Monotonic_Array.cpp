using namespace std;

bool isMonotonic(vector<int> array) {
  // Write your code here.
	bool non_inc = true;
	if (array.size() < 2)
		return true;
	if (array[0] <= array[array.size() -1])
		non_inc = false;
	for (int i = 0; i < array.size() - 1; i++) {
		if (non_inc) {
			if (array[i] < array[i + 1])
				return false;
		} else {
			if (array[i] > array[i + 1])
				return false;
		}
	}
  return true;
}

