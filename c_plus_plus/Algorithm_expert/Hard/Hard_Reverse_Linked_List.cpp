using namespace std;

class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    this->next = nullptr;
  }
};

LinkedList *reverseLinkedList(LinkedList *head, LinkedList *prev = nullptr) {
  // Write your code here.
	#if 0
	//iterative
	if (!head) return nullptr;
	LinkedList *cur = head;
	LinkedList *prev = nullptr;

	while (cur) {
		LinkedList *t = cur->next;
		cur->next = prev;
		prev = cur;
		cur = t;
	}
  	return prev;
	#endif
	
	#if 1
	//recursive
	if (!head) return nullptr;
	if (!head->next) {
		head->next = prev;
		return head;
	}
	LinkedList *rc = reverseLinkedList(head->next, head);
	head->next = prev;
	return rc;
	#endif
}


