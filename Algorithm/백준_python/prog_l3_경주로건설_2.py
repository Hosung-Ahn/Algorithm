

def solution(board) :
    N = len(board)
    visited = [[False for _ in range(N)] for _ in range(N)]
    
    def in_range(r,c) :
        if r<0 or r>=N or c<0 or c>= N : return False
        return True
    
    ans = 987654321
    dr = [-1,0,1,0]
    dc = [0,1,0,-1]
    
    def dfs(r, c, d,cost) :
        nonlocal ans
        if not in_range(r,c) or board[r][c] == 1 or visited[r][c] : return
        if r == N-1 and c == N-1 : 
            ans = min(ans, cost)
            return True
        visited[r][c] = True
        print(r,c,d, cost)    
        
        left=(d-1)
        if left < 0 : left += 4
        right = (d+1)%4
        dfs(r+dr[d], c+dc[d],d, cost+100)
        dfs(r+dr[left], c+dc[left], left, cost+600)
        dfs(r+dr[right], c+dc[right], right, cost+600)
        
        visited[r][c] = False
        
    dfs(0,0,1,0)
    return ans
        
print(solution([[0, 0, 0], [0, 0, 0], [0, 0, 0]]))