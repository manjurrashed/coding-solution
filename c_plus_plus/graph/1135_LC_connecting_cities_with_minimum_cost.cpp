class Set {
    public:
    vector<int> parent;
    
    Set(int n) : parent(n + 1) {
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }
    int find(int a) {
        //it basically returns parent when both value and parent are same.
        while (a != parent[a]) {
            //speed up by path compression
            parent[a] = parent[parent[a]];
            a = parent[a];
        }
        return a;
    }
    void setUnion(int a, int b) {
        //join the parents if they are different.
        int rootA = parent[a];
        int rootB = parent[b];
        if (rootA == rootB)
            return;
        if (rootA < rootB)
            parent[rootB] = rootA;
        else
            parent[rootA] = rootB;
    }
    bool allJoined(){
        int a = parent.size() - 1;
        while (a != parent[a])
            a = parent[a];
        if (a == 1)
            return true;
        return false;
    }
};

bool mycompare(vector<int> &a, vector<int> &b) {
    if (a[2] < b[2])
        return true;
    return false;
}

class Solution {

public:
    int minimumCost(int N, vector<vector<int>>& connections) {

        Set myset(N);
        std::sort( connections.begin(), connections.end(), mycompare);

        int sum = 0;
        for (auto itr : connections) {
            if (myset.find(itr[0]) != myset.find(itr[1])) {
                sum += itr[2];
                myset.setUnion(itr[0], itr[1]);
            }
        }
        if (!myset.allJoined())
            return -1;
        return sum;
    }
};

