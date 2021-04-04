using namespace std;

vector<int> sunsetViews(vector<int> buildings, string direction) {
  // Write your code here.
	int start = 0;
	int inc = 1;
	int end = buildings.size();
	vector<int> result;
	if (direction.compare("EAST") == 0) {
		start = buildings.size() - 1;
		inc = -1;
		end = -1;
	}
	int max = INT_MIN;
	for (int i = start; i != end; i += inc) {
		if (buildings[i] > max) {
			max = buildings[i];
			result.push_back(i);
		}
	}
	if (direction.compare("EAST") == 0) {
		reverse(result.begin(), result.end());
	}
  return result;
}

