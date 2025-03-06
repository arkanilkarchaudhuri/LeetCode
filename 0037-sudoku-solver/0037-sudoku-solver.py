class Solution(object):
    def solveSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: None Do not return anything, modify board in-place instead.
        """
        def is_valid(board, row, col, num):
            """
            Check if it's valid to place the number `num` at position (row, col).
            """
            block_row, block_col = 3 * (row // 3), 3 * (col // 3)
            for i in range(9):
                if board[row][i] == num:  # Check row
                    return False
                if board[i][col] == num:  # Check column
                    return False
                if board[block_row + i // 3][block_col + i % 3] == num:  # Check 3x3 sub-box
                    return False
            return True
        
        def solve(board):
            """
            Use backtracking to solve the Sudoku board.
            """
            for row in range(9):
                for col in range(9):
                    if board[row][col] == '.':
                        for num in '123456789':
                            if is_valid(board, row, col, num):
                                board[row][col] = num
                                if solve(board):
                                    return True
                                board[row][col] = '.'  # Backtrack
                        return False  # If no number is valid, trigger backtracking
            return True  # If all cells are filled
        
        solve(board)