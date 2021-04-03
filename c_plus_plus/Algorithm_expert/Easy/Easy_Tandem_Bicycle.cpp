#include <vector>
using namespace std;

int tandemBicycle(vector<int> redShirtSpeeds, vector<int> blueShirtSpeeds,
                  bool fastest) {
  // Write your code here.
	sort(redShirtSpeeds.begin(), redShirtSpeeds.end(), [](int a, int b){return a < b; });
	sort(blueShirtSpeeds.begin(), blueShirtSpeeds.end(), [fastest](int a, int b){return (fastest)? ( a > b) : (a < b);});
  int sum = 0;
	for (int i = 0; i < redShirtSpeeds.size(); i++) {
		sum += max(redShirtSpeeds[i], blueShirtSpeeds[i]);
	}
	return sum;
}

