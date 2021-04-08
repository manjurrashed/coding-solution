using namespace std;

int longestPeak(vector<int> array) {
  // Write your code here.
	int max_len = 0;
	int size = array.size();
	for (int i = 1; i < size - 1; i++) {
		if (array[i - 1] < array[i] && array[i] > array[i + 1]) {
			int left = i;
			int right = i;
			while (left > 0 && array[left - 1] < array[left]) {
				left--;
			}
			while (right < size - 1 && array[right] > array[right + 1]) {
				right++;
			}
			max_len = max(max_len, right - left + 1);

			i = right;
		}
	}
  return max_len;
}

