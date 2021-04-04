using namespace std;

// This is an input struct. Do not edit.
class LinkedList {
public:
  int value;
  LinkedList *next = nullptr;

  LinkedList(int value) { this->value = value; }
};

LinkedList *sumOfLinkedLists(LinkedList *linkedListOne,
                             LinkedList *linkedListTwo) {
  // Write your code here.
	LinkedList dummy(0);
	LinkedList *cur = &dummy;
	int sum = 0;
	int carry = 0;
	while (linkedListOne || linkedListTwo || carry) {
		sum = carry;
		if (linkedListOne) {
			sum += linkedListOne->value;
			linkedListOne = linkedListOne->next;
		}
		if (linkedListTwo) {
			sum += linkedListTwo->value;
			linkedListTwo = linkedListTwo->next;
		}
		carry = (sum > 9) ? 1 : 0;
		sum = (sum > 9) ? sum - 10 : sum;
		cur->next = new LinkedList(sum);
		cur = cur->next;
	}

  return dummy.next;
}
