using namespace std;

string caesarCypherEncryptor(string str, int key) {
  	// Write your code here.
	string result = "";
	for (auto ch: str) {
		char x = ((ch - 'a') + key) % 26;
		result += (x + 'a');
	}
  	return result;
}

