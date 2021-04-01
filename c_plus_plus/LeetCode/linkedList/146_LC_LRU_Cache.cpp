class Node {
public:
    int key;
    int value;
    Node *next;
    Node *prev;
    Node(int k, int v) {
        key = k;
        value = v;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    int size;
    int capacity;
    unordered_map<int, Node *> map;
    Node *head;
    Node *tail;
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        size = 0;
        head = nullptr;
        tail = nullptr;
    }
    
    void moveFront(int key, int value) {
        Node *cur = map[key];
        cur->value = value;
        if (cur == tail && cur == head) 
            return;
        if (cur == head)
            return;
        if (cur == tail) {
            tail = tail->prev;
        } else {
            // if cur is not head and tail, that means we have at least 3 elements.
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
        }
        cur->next = head;
        cur->prev = nullptr;
        head->prev = cur;
        head = cur;
    }
    
    int get(int key) {
        // Returnning value at O(1)
        if (map.find(key) == map.end())
            return -1;
        else {
            moveFront(key, map[key]->value);
            return map[key]->value;
        }
    }
    
    void put(int key, int value) {        
        if (map.find(key) == map.end()) {
            //if does not existing put at the front.
            //if reach at the capaity remove the last Node.
            Node *cur = new Node(key, value);
            map[key] = cur;
            if (size < capacity) {
                if (head == nullptr && tail == nullptr) {
                    head = cur;
                    tail = cur;
                } else {   
                    cur->next = head;
                    head->prev = cur;
                    head = cur;
                }
                size++;
            } else {
                cur->next = head;
                head->prev = cur;
                head = cur;
                map.erase(tail->key);
                tail = tail->prev;
                delete tail->next;
                tail->next = nullptr;
            }
            
        } else {
            //if exist, remove and put at the front.
            moveFront(key, value);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
