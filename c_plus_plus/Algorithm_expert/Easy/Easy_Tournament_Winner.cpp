#include <vector>
using namespace std;

string tournamentWinner(vector<vector<string>> competitions,
                        vector<int> results) {
  // Write your code here.
	unordered_map<string, int> map;
	for (int i = 0; i < results.size(); i++) {
		if (results[i] == 1) {
			map[competitions[i][0]]+=3;
		} else {
			map[competitions[i][1]]+=3;
		}
	}
	int max_point = INT_MIN;
	string winner;
	for (auto d : map) {
		if (d.second > max_point) {
			max_point = d.second;
			winner = d.first;
		}
	}
  return winner;
}

