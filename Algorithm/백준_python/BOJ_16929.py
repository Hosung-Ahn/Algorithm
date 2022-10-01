import sys
input = sys.stdin.readline

R,C = map(int, input().split())
board = []
for _ in range(R) :
    s = input()
    board.append(s)
    
total_visited = [[False for _ in range(C)] for _ in range(R)]
dr = [-1,0,1,0]
dc = [0,-1,0,1]

def solve() :
    ans = False
    
    visited = [[False for _ in range(C)] for _ in range(R)]
    
    def in_range(r,c) :
        if r<0 or r>=R or c<0 or c>=C : return False
        return True
    
    def dfs(r,c,cnt) :
        nonlocal ans
        total_visited[r][c] = True
        for i in range(4) :
            nr = r+dr[i]
            nc = c+dc[i]
            ncnt = cnt + 1
            if not in_range(nr,nc) or board[nr][nc] != board[r][c] : continue
            if visited[nr][nc] != 0 and ncnt - visited[nr][nc] >= 4 :
                ans = True
            if visited[nr][nc]==0 :
                visited[nr][nc] = ncnt
                dfs(nr,nc,ncnt)
                visited[nr][nc] = 0
                
    for r in range(R) :
        for c in range(C) :
            if total_visited[r][c] : continue
            visited[r][c] = True
            dfs(r,c,1)
            visited[r][c] = False
            
    if ans : print('Yes')
    else : print('No')
    
    
solve()