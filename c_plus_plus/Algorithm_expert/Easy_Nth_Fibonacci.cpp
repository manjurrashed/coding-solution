using namespace std;

int getNthFib(int n) {
  // Write your code here.
	#if 0
	//recursive
	if (n == 1)
		return 0;
	if (n == 2)
		return 1;
	return getNthFib(n - 1) + getNthFib(n - 2);
	#endif
	
	#if 0
	//iterative
	int f1 = 0;
	int f2 = 1;

	if (n == 1)
		return 0;
	if (n == 2)
		return 1;

	for (int i = 3; i <= n; i++) {
		int temp = f1 + f2;
		f1 = f2;
		f2 = temp;
	}
	return f2;
	#endif
}

