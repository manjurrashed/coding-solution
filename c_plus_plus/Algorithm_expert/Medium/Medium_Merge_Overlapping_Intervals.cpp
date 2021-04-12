#include <vector>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> intervals) {
  // Write your code here.
	vector<vector<int>> result;
	sort(intervals.begin(), intervals.end(), [](auto a, auto b){ return a[0] < b[0];});
	int start = 0;
	int finish = 0;
	for (int i = 0; i < intervals.size(); i++) {
		finish = max(finish, intervals[i][1]);
		if ((i < intervals.size() - 1 && finish < intervals[i + 1][0]) || i == intervals.size() - 1) {
			result.push_back({intervals[start][0], max(intervals[start][1], intervals[i][1])});
			start = i + 1;
		}
	}
  return result;
}

