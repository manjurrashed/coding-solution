using namespace std;

string runLengthEncoding(string str) {
  // Write your code here.
	#if 0
	int slow = 0;
	int fast = 0;
	int cnt = 0;
	string result = "";
	for (; fast < str.length(); fast++) {
		if (str[slow] == str[fast] && cnt < 9) {
			cnt++;
		} else {
			result += std::to_string(cnt) + str[slow];
			slow = fast;
			cnt = 1;
		}
	}
	result += std::to_string(cnt) + str[fast - 1];
  return result;
	#endif

	#if 1
	string result = "";
	int i;
	int cnt = 1;
	for (i = 1; i < str.length(); i++) {
		if (str[i - 1] == str[i] && cnt < 9) {
			cnt++;
		} else {
			result += std::to_string(cnt) + str[i - 1];
			cnt = 1;
		}
	}
	result += std::to_string(cnt) + str[i - 1];	
	return result;
	
	#endif
}

