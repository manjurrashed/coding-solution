class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        auto mycompare = [](int a, int b){
            auto bits = [](int x){int cnt = 0; while (x) { cnt++; x = x & (x - 1); } return cnt;};
            int ab = bits(a); 
            int bb = bits(b); 
            return (ab == bb) ? (a < b) : (ab < bb);
        };
        
        sort(arr.begin(), arr.end(), mycompare);
        return arr;
    }
};
