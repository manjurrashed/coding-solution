using namespace std;

bool palindromic(string &str) {
	int left = 0;
	int right = str.length() - 1;
	while (left < right) {
		if (str[left++] != str[right--])
			return false;
	}
	return true;
}
string getPalindrom(string &str, int left, int right) {
	while (left >= 0 && right < str.length() && str[left] == str[right]) {
			left--;
			right++;
	}
	left++;
	right--;
	return str.substr(left, right - left + 1);
}
string longestPalindromicSubstring(string str) {
  // Write your code here.
	#if 0
	//O(n^3)
	string max_str;
	for (int i = 0; i < str.length(); i++) {
		for (int j = i; j < str.length(); j++) {
			string substr = str.substr(i, j - i + 1);
			if (substr.length() > max_str.length() && palindromic(substr)) {
				max_str = substr;
			}
		}
	}
  return max_str;
	#endif
	#if 1
	//O(n^2)
	string max_str;
	for (int i = 0; i < str.length(); i++) {
		string even = getPalindrom(str, i, i + 1);
		max_str = (even.length() > max_str.length()) ? even : max_str;
		string odd = getPalindrom(str, i, i);
		max_str = (odd.length() > max_str.length()) ? odd : max_str;
	}
	return max_str;
	#endif
}

