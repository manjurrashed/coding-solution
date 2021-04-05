#include <stack>
using namespace std;

bool balancedBrackets(string str) {
  // Write your code here.
	stack<char> st;
	for (auto ch : str) {
		if (ch == '(' || ch == '{' || ch == '[')
			st.push(ch);
		if (ch == ')') {
			 if (!st.empty() && st.top() == '(')
				 st.pop();
			else
				return false;
		}
		if (ch == '}') {
			 if (!st.empty() && st.top() == '{')
				 st.pop();
			else
				return false;
		}
		if (ch == ']') {
			 if (!st.empty() && st.top() == '[')
				 st.pop();
			else
				return false;
		}
	}
  return st.empty();
}

