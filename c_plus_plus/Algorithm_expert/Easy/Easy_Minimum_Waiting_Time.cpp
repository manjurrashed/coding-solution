using namespace std;

int minimumWaitingTime(vector<int> queries) {
  // Write your code here.
	sort(queries.begin(), queries.end(), [](int a, int b) { return a < b;});
	int result = 0;
	int sum = 0;
	for (int i = 0; i < queries.size() - 1; i++) {
		sum += queries[i];
		result += sum;
	}
  return result;
}

