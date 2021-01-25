class Solution {
public:
    int totalFruit(vector<int>& tree) {
        unordered_map<int, int> count_map;
        int left = 0;
        int count = 0;
        int result = 0;
        for (auto fruit : tree) {
            count_map[fruit]++;
            count++;
            while (count_map.size() > 2) {
                count_map[tree[left]]--;
                count--;
                if (count_map[tree[left]] == 0)
                    count_map.erase(tree[left]);
                left++;
            }
            result = max(result, count);
        }

        return result;
    }
};
