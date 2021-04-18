class Node {
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int key, int value) {
        prev = nullptr;
        next = nullptr;
        this->key = key;
        this->value = value;
    }
};

class LRUCache {
    int size;
    unordered_map<int, Node *> map;
    Node *head;
    Node *tail;
public:
    LRUCache(int capacity) {
        size = capacity;
        head = nullptr;
        tail = nullptr;
    }
    
    void add_front(Node *front) {
        if (!front)
            abort();
        front->next = head;
        if (head)
            head->prev = front;
        head = front;
        if (!tail)
            tail = front;
    }
    void remove_element(Node *temp) {
        if(!temp)
            abort();
        if (temp->prev)
            temp->prev->next = temp->next;
        if (temp->next)
            temp->next->prev = temp->prev;
        else
            tail = temp->prev;
    }
    void move_to_front(int key) {
        //more than one, not front
        if (head != tail && head != map[key]) {
            Node *temp = map[key];
            //delete 2nd, midle or last.
            remove_element(temp);
            //add to the front.
            add_front(temp);
        }
    }
    
    void add_front_remove_back(int key) {
        Node *front = map[key];
        //add front
        add_front(front);
        //remove back
        if (map.size() > size) {
            Node *back = tail;
            remove_element(back);
            map.erase(back->key);
            delete back;
        }
    }
    
    int get(int key) {
        if (map.find(key) == map.end())
            return -1;
        move_to_front(key);
        return map[key]->value;
    }
    
    void put(int key, int value) {
        if (map.find(key) != map.end()) {
            map[key]->value = value;
            move_to_front(key);
        } else {
            //new, push front, pop back.
            map[key] = new Node(key, value);
            add_front_remove_back(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
