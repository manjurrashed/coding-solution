using namespace std;

// Do not edit the class below except for the insertKeyValuePair,
// getValueFromKey, and getMostRecentKey methods. Feel free
// to add new properties and methods to the class.
class Node {
	public:
	string key;
	int val;
	Node *prev;
	Node *next;
	Node(string key, int val) {
		this->key = key;
		this->val = val;
		prev = nullptr;
		next = nullptr;
	}
};

class LRUCache {
public:
  int maxSize;
	string most_recent_key;
	unordered_map<string, Node *> map;
	Node *head;
	Node *tail;

  LRUCache(int maxSize) {
		this->maxSize = maxSize > 1 ? maxSize : 1;
		head = nullptr;
		tail = nullptr;
	}
	
	void add_front(Node *temp) {
		if (!temp)
			abort();
		if (head == temp)
			return;
		if (head)
			head->prev = temp;
		temp->next = head;
		temp->prev = nullptr;
		head = temp;
		if (!tail)
			tail = temp;
	}
	
	void remove(Node *temp) {
		if (!temp)
			abort();
		if (temp->prev)
			temp->prev->next = temp->next;
		if (temp->next)
			temp->next->prev = temp->prev;
		else
			tail = temp->prev;
	}
	
	void move_to_front(string key) {
		Node *temp = map[key];
		if (head == temp || head == tail)
			return;
		remove(temp);
		add_front(temp);
	}
	
	void add_front_remove_back(string key) {
		Node *temp = map[key];
		add_front(temp);
		if (map.size() > maxSize) {
			temp = tail;
			remove(temp);
			map.erase(temp->key);
			delete temp;
		}
	}
	
  void insertKeyValuePair(string key, int value) {
    // Write your code here.
		if (map.find(key) != map.end()) {
			map[key]->val = value;
			move_to_front(key);
		} else {
			map[key] = new Node(key, value);
			add_front_remove_back(key);
		}
		most_recent_key = key;
  }

  int *getValueFromKey(string key) {
    // Write your code here.
		if (map.find(key) == map.end()) {
			return nullptr;
		}
		move_to_front(key);
		most_recent_key = key;
    return &map[key]->val;
  }

  string getMostRecentKey() {
    // Write your code here.
    return most_recent_key;
  }
};

