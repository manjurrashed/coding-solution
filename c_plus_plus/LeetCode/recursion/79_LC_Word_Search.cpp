class Solution {
public:
    bool backtrack(vector<vector<char>>& board, vector<vector<bool>> &visit, int row, int col, string &word, int idx) {
        bool rc;
        if (idx == word.length())
            return true;
        
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size())
            return false;

        if (board[row][col] != word[idx]) 
            return false;
        
        if (visit[row][col] == true)
            return false;
        
        visit[row][col] = true;
        rc =  backtrack(board, visit, row - 1, col, word, idx + 1) ||
            backtrack(board, visit, row + 1, col, word, idx + 1) ||
            backtrack(board, visit, row, col + 1, word, idx + 1) ||
            backtrack(board, visit, row, col - 1, word, idx + 1);
        visit[row][col] = false;
        return rc;
        
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visit(board.size(), vector<bool>(board[0].size(), false));
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] == word[0] &&  backtrack(board, visit, row, col, word, 0)) {
                     return true;
                }
            }
        }
        return false;
    }
};
