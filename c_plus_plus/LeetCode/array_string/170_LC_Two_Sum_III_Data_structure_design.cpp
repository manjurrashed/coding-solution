class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<int, int> map;
    TwoSum() {
        
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        map[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        for (auto data : map) {
            long diff = static_cast<long>(value) - data.first;
            if (diff == data.first && data.second == 1)
                continue;
            if (map.count(diff) == 1) {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
