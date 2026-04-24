class Solution:
    def knightTour(self, n):
        board = [[-1 for _ in range(n)] for _ in range(n)]
        
        # 8 possible moves of knight
        dx = [2, 1, -1, -2, -2, -1, 1, 2]
        dy = [1, 2, 2, 1, -1, -2, -2, -1]
        
        def isSafe(x, y):
            return 0 <= x < n and 0 <= y < n and board[x][y] == -1
        
        def solve(x, y, move):
            if move == n * n:
                return True
            
            for i in range(8):
                nx = x + dx[i]
                ny = y + dy[i]
                
                if isSafe(nx, ny):
                    board[nx][ny] = move
                    if solve(nx, ny, move + 1):
                        return True
                    board[nx][ny] = -1   # backtrack
            
            return False
        
        # start from (0,0)
        board[0][0] = 0
        
        if not solve(0, 0, 1):
            return []   # no solution
        
        return board
