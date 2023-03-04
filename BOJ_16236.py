from collections import deque

N = int(input())
board = []
for _ in range(N) :
    board.append(list(map(int, input().split())))
    
dr = [-1,0,1,0]
dc = [0,-1,0,1]
eat = 0
size = 2
ans = 0
r = -1
c = -1


def in_range(r,c) :
    if r<0 or r>=N or c<0 or c>=N : return False
    return True
    
def bfs() :
    global eat, ans, r, c, size
    visited = [[-1 for _ in range(N)] for _ in range(N)]
    visited[r][c] = 0
    q = deque()
    q.append([r,c])
    tmp = []

    board[r][c] = 0
    
    while q : 
        cr,cc = q.popleft()
        
        if board[cr][cc] != 0 and board[cr][cc] < size : 
            tmp.append([visited[cr][cc], cr,cc])
        
        for i in range(4) :
            nr = cr + dr[i]
            nc = cc + dc[i]
            if not in_range(nr,nc) or visited[nr][nc]>=0 or board[nr][nc] > size: continue
            visited[nr][nc] = visited[cr][cc] + 1
            q.append([nr,nc])
            
    if len(tmp) == 0 : return False
    else : 
        tmp.sort()
        r = tmp[0][1]
        c = tmp[0][2]
        
        board[r][c] = 9
        eat += 1
        if eat == size :
            size += 1
            eat = 0
        ans += tmp[0][0]
        return True
        

for i in range(N) :
    for j in range(N) :
        if board[i][j] == 9:
            r = i
            c = j
            

while bfs() :
    pass
            
print(ans)
        
        
    