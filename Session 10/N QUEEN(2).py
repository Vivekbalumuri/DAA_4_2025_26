class Solution(object):
    def solveNQueens(self, n):
        def backtrack(row):
            if row == n:
                board = []
                for r in range(n):
                    row_str = ""
                    for c in range(n):
                        if (r, c) in queens:
                            row_str += "Q"
                        else:
                            row_str += "."
                    board.append(row_str)
                result.append(board)
                return
            
            for col in range(n):
                if col in cols or (row - col) in diag1 or (row + col) in diag2:
                    continue
                
                # place queen
                queens.add((row, col))
                cols.add(col)
                diag1.add(row - col)
                diag2.add(row + col)
                
                backtrack(row + 1)
                
                # remove queen (backtrack)
                queens.remove((row, col))
                cols.remove(col)
                diag1.remove(row - col)
                diag2.remove(row + col)

        result = []
        queens = set()
        cols = set()
        diag1 = set()
        diag2 = set()
        
        backtrack(0)
        return result
