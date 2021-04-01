class Solution {
public:
    int maxNumberOfApples(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        int w = 0;
        int c = 0;
        
        for (auto x : arr) {
            w += x;
            if (w > 5000)
                break;
            c++;
        }
        return c;
    }
};

