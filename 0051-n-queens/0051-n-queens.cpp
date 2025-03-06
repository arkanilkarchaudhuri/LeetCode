class Solution {
public:
    std::vector<std::vector<std::string>> solveNQueens(int n) {
        std::vector<std::vector<std::string>> solutions;
        std::vector<int> queens(n, -1); 
        std::vector<bool> cols(n, false);      
        std::vector<bool> diag1(2 * n - 1, false); 
        std::vector<bool> diag2(2 * n - 1, false); 

        backtrack(solutions, queens, cols, diag1, diag2, 0, n);
        return solutions;
    }

private:
    void backtrack(std::vector<std::vector<std::string>>& solutions, std::vector<int>& queens,
                   std::vector<bool>& cols, std::vector<bool>& diag1, std::vector<bool>& diag2,
                   int row, int n) {
        if (row == n) {
            solutions.push_back(generateBoard(queens, n));
            return;
        }
        
        for (int col = 0; col < n; ++col) {
            int d1 = row - col + n - 1;
            int d2 = row + col;
            
            if (cols[col] || diag1[d1] || diag2[d2]) {
                continue; 
            }
            
       
            queens[row] = col;
            cols[col] = diag1[d1] = diag2[d2] = true;
            
         
            backtrack(solutions, queens, cols, diag1, diag2, row + 1, n);
            
           
            queens[row] = -1;
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }

    std::vector<std::string> generateBoard(const std::vector<int>& queens, int n) {
        std::vector<std::string> board(n, std::string(n, '.'));
        for (int i = 0; i < n; ++i) {
            board[i][queens[i]] = 'Q';
        }
        return board;
    }
};