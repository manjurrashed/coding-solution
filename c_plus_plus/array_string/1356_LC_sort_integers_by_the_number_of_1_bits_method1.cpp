class Solution {
public:
    static int bitcount(int n) {
        int count = 0;
        while (n) {
            n = n & (n - 1);
            count++;
        }
        return count;
    }
    static bool num_compare(int i, int j) {
        int ib = bitcount(i);
        int jb = bitcount(j);
        
        return (ib == jb) ? (i < j) : (ib < jb);
    }
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), num_compare);
        return arr;
    }
};
