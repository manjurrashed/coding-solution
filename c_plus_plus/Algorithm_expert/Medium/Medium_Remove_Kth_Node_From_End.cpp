#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
  void addMany(vector<int> values);
  vector<int> getNodesInArray();
};

void helper(LinkedList *head, int &k) {
	if (head == nullptr)
		return;
	helper(head->next, k);
	if (k == 0) {
		LinkedList *t = head->next;
		head->next = t->next;
		delete t;
	}
	k--;
}

void removeKthNodeFromEnd(LinkedList *head, int k) {
  // Write your code here.
	#if 0
	//iterative
	LinkedList dummy(-1);
	dummy.next = head;
	LinkedList *slow = &dummy;
	LinkedList *fast = head;

	while (fast && k > 0) {
		fast = fast->next;
		k--;
	}
	while (fast) {
		fast = fast->next;
		slow = slow->next;
	}
	cout << slow->value << endl;
	if (slow == &dummy) {
		LinkedList *t = slow->next->next;
		*(slow->next) = *(slow->next->next);
		delete t;
	} else {
		LinkedList *t = slow->next;
		slow->next = (t) ? t->next : nullptr;
		delete t;
	}
	#endif
	#if 1
	//recursive
	helper(head, k);
	if (k == 0) {
		LinkedList *t = head->next;
		*head = *t;
		delete t;
	}
	#endif
}

