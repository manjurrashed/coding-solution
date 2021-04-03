using namespace std;

int firstNonRepeatingCharacter(string string) {
  // Write your code here.
	unordered_map<char, int> map;
	for (auto ch : string)
		map[ch]++;
	for (int i = 0; i < string.length(); i++)
		if (map[string[i]] == 1)
			return i;
  return -1;
}

