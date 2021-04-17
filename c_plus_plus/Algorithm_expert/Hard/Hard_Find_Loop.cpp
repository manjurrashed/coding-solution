#include <vector>
using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value);
};

LinkedList *findLoop(LinkedList *head) {
  // Write your code here.
	if (!head) return nullptr;
	LinkedList *fast = head;
	LinkedList *slow = head;
	while (fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
		if (fast == slow)
			break;
	}
	
	fast = head;
	while (slow && fast != slow) {
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

