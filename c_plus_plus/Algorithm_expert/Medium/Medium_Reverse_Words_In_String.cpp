using namespace std;

void reverse(string &str, int left, int right) {
	while(left < right) swap(str[left++], str[right--]);
}
string reverseWordsInString(string str) {
  // Write your code here.
	reverse(str, 0, str.length() - 1);
	int left = 0;
	for (int right = 0; right <= str.length(); right++) {
		if (str[right] == ' ' || right == str.length()) {
			reverse(str, left, right - 1);
			left = right + 1;
		}
	}
  return str;
}

