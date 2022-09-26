from itertools import combinations
import sys

input = sys.stdin.readline

board = []
for _ in range(5) :
    s = input()
    board.append(s)

selected = [[0 for _ in range(5)] for _ in range(5)]
combs = combinations(range(25),7)

def in_range(r,c) :
    if r<0 or r>=5 or c<0 or c>=5 : return False
    return True

def bfs(selected, r,c) :
    dr = [-1,0,1,0]
    dc = [0,-1,0,1]
    selected[r][c] = 0
    q = [[r,c]] 
    cnt = 1
    while q :
        cr = q[0][0]
        cc = q[0][1]
        q.pop(0)
        
        for i in range(4) :
            nr = cr + dr[i]
            nc = cc + dc[i]
            if not in_range(nr,nc) or selected[nr][nc] == 0 : continue
            q.append([nr,nc])
            selected[nr][nc] = 0
            cnt += 1
            
    return cnt == 7
            
ans = 0

for comb in combs :
    cnt = 0
    selected = [[0 for _ in range(5)] for _ in range(5)]
    r = 0
    c = 0
    for i in comb :
        r = i//5
        c = i%5
        if board[r][c] == 'S' : cnt += 1
        selected[r][c] = 1
        
    if cnt < 4 or not bfs(selected, r,c): continue
    ans += 1
    
print(ans)
    
        
        
        




