using namespace std;

bool generateDocument(string characters, string document) {
  // Write your code here.
	//document <= char.
	unordered_map<char, int> mc;
	unordered_map<char, int> md;
	for (auto ch : characters)
		mc[ch]++;
	for (auto ch : document)
		md[ch]++;
	
	for (auto d : md) {
		if (d.second > mc[d.first])
			return false;
	}
  return true;
}

