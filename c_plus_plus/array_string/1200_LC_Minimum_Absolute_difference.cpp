class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [](int a, int b) { return a < b; });
        int diff = INT_MAX;
        for (int i = 1; i < arr.size(); i++) {
            diff = min(diff, arr[i] - arr[i - 1]);
        }
        vector<vector<int>> result;
        for (int i = 1; i < arr.size(); i++) {
            if (diff == arr[i] - arr[i - 1]) {
                result.push_back({arr[i - 1], arr[i]});
            }
        }
        return result;
    }
};
