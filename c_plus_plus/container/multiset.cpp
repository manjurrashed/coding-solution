#include <iostream>
#include <set>
using namespace std;
int main() {
	multiset<int> mset;
	for (int i = 0; i < 100; i+=10) 
		mset.insert(i);
	auto low = mset.lower_bound(35);
	auto up = mset.upper_bound(35);

	cout << *low << endl;
	cout << *up << endl;
}
