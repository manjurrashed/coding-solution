class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        
        vector<pair<pair<int,int>, int>> mapA;
        vector<pair<pair<int,int>, int>> mapB;

        for (int r = 0; r < A.size(); r++) {
            for (int c = 0; c < A[0].size(); c++) {
                if (A[r][c])
                    mapA.push_back({{r, c}, A[r][c]});
            }
        }
        
        for (int r = 0; r < B.size(); r++) {
            for (int c = 0; c < B[0].size(); c++) {
                if (B[r][c])
                    mapB.push_back({{r, c}, B[r][c]});
            }
        }
        
        vector<vector<int>> result(A.size(), vector<int>(B[0].size(), 0));

        for (auto itrA : mapA) {
            for (auto itrB : mapB) {
                if (itrA.first.second == itrB.first.first) {
                    result[itrA.first.first][itrB.first.second] += itrA.second * itrB.second;
                }
            }
        }

        return result;
    }
};

