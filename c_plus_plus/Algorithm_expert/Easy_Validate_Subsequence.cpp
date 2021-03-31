using namespace std;

bool isValidSubsequence(vector<int> array, vector<int> sequence) {
  // Write your code here.
	int idx = 0;
	for (auto n : array) {
		if (n == sequence[idx]) {
			idx++;
		}
		if (idx == sequence.size())
			return true;
	}
  return false;
}

