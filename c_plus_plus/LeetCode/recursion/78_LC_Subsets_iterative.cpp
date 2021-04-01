class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;

        vector<int> data;
        result.push_back(data);

        for (auto n : nums) {
            int size = result.size();
            for (int i = 0; i < size; i++) {
                data = result[i];
                data.push_back(n);
                result.push_back(data);
            }
        }
        
        return result;
    }
};
