using namespace std;

bool isPalindrome(string str) {
  // Write your code here.
	int left = 0, right = str.length() - 1;
	while (left < right) {
		if (str[left++] != str[right--])
			return false;
	}
  return true;
}

