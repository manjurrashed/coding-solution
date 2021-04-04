#include <vector>
using namespace std;

int firstDuplicateValue(vector<int> array) { 
	unordered_set<int> set;
	for (auto n : array) {
		if (set.find(n) != set.end()) {
			return n;
		}
		set.insert(n);
	}
	return -1;
}

