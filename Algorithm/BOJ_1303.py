from collections import deque

C,R = map(int, input().split())
board = []

for _ in range(R) :
    s = input()
    board.append(s)
    
    
dr = [-1,0,1,0]
dc = [0,-1,0,1]

visited = [[False for _ in range(C)] for _ in range(R)]

def in_range(r,c) :
    if r<0 or r>=R or c<0 or c>=C : return False 
    return True

def bfs(r,c) :
    visited[r][c] = True
    q = deque([[r,c]])
    target = board[r][c]
    
    ret = 1
    
    while q :
        cr,cc = q.popleft()
        for i in range(4) : 
            nr = cr + dr[i]
            nc = cc + dc[i]
            
            if not in_range(nr,nc) or visited[nr][nc] or board[nr][nc] != target: continue
            ret += 1
            visited[nr][nc] = True
            q.append([nr,nc])
            
    return ret

ans = [0,0]

for r in range(R) :
    for c in range(C) :
        if visited[r][c] : continue
        
        if board[r][c] == 'W' :
            ans[0] += bfs(r,c) ** 2
        else :
            ans[1] += bfs(r,c) ** 2
            
print(*ans)