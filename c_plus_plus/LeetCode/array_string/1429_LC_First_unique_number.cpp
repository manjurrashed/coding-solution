class FirstUnique {
    unordered_map<int, int> map;
    queue<int> q;
public:
    FirstUnique(vector<int>& nums) {
        for (auto n : nums) {
            add(n);
        }
    }
    
    int showFirstUnique() {
        while (!q.empty()) {
            if (map[q.front()] == 1)
                return q.front();
            q.pop();
        }
        return -1;
    }
    
    void add(int value) {
        map[value]++;
        if (map[value] == 1)
            q.push(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
