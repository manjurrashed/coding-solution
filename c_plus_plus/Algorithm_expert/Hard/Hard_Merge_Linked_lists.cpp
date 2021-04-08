#include <vector>

using namespace std;

// This is an input class. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next;

  LinkedList(int value) {
    this->value = value;
    next = nullptr;
  }
};

LinkedList *mergeLinkedLists(LinkedList *headOne, LinkedList *headTwo) {
  // Write your code here.
	LinkedList dummy(-1);
	LinkedList *cur = &dummy;
	while (headOne || headTwo) {
		if (headOne && headTwo) {
			if (headOne->value < headTwo->value) {
				cur->next = headOne;
				headOne = headOne->next;
				cur = cur->next;
			} else {
				cur->next = headTwo;
				headTwo = headTwo->next;
				cur = cur->next;
			}
		} else if (headOne) {
				cur->next = headOne;
				break;
		} else {
				cur->next = headTwo;
				break;
		}
	}
  return dummy.next;
}

