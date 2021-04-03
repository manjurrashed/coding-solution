using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *removeDuplicatesFromLinkedList(LinkedList *linkedList) {
  // Write your code here.
	LinkedList *slow = linkedList;
	LinkedList *fast = linkedList->next;
	while (fast) {
		if (slow->value == fast->value) {
			slow->next = fast->next;
			delete fast;
			fast = slow->next;
		} else {
			slow = fast;
			fast = fast->next;
		}
	}
  return linkedList;
}

