import sys
from queue import Queue

input = sys.stdin.readline

R,C = map(int, input().split())
board = []
for _ in range(R) :
    s = list(input())
    s.pop()
    board.append(s)
    
N = int(input())
h_lst = list(map(int, input().split()))

def bar(h, d) :
    h = R-h
    idx = list(range(C))
    if d : idx.reverse()
    
    for i in idx :
        if board[h][i] == 'x' :
            board[h][i] = '.'
            return
    
def fall() :
    visited = [ [False for _ in range(C)] for _ in range(R) ]
    dr = [-1,0,1,0]
    dc = [0,-1,0,1]
    
    def in_range(r,c) :
        if r < 0 or r >= R or c < 0 or c >= C : return False
        return True
    
    def is_air(r,c) :
        visited[r][c] = True
        q = Queue()
        q.put([r,c])
        while(not q.empty()) :
            cr,cc = q.get()
            if cr == R-1 : return False
            for i in range(4) :
                nr = cr + dr[i]
                nc = cc + dc[i]
                if not in_range(nr, nc) or visited[nr][nc] or board[nr][nc] == '.':
                    continue
                visited[nr][nc] = True
                q.put([nr,nc])
        return True
    
    def cal_dist(r,c) :
        local_visited = [ [False for _ in range(C)] for _ in range(R) ]
        
        def tmp_dist(r,c) :
            ret = 0
            for nr in range(r+1,R) :
                if local_visited[nr][c] : return 1000
                if board[nr][c] == 'x' : return ret
                ret+=1
            return ret
    
        dist = 1000
        q = Queue()
        q.put([r,c])
        local_visited[r][c] = True
        while(not q.empty()) :
            cr,cc = q.get()
            for i in range(4) :
                nr = cr + dr[i]
                nc = cc + dc[i]
                if not in_range(nr, nc) or local_visited[nr][nc] or board[nr][nc] == '.':
                    continue
                local_visited[nr][nc] = True
                q.put([nr,nc])
                
        for cr in range(R) : 
            for cc in range(C) :
                if local_visited[cr][cc] :
                    dist = min(dist, tmp_dist(cr,cc))
                    
        for cr in range(R-1,-1,-1) :
            for cc in range(C-1,-1,-1) :
                if local_visited[cr][cc] :
                    board[cr][cc] = '.'
                    board[cr+dist][cc] = 'x'
        
    
    for r in range(R) :
        for c in range(C) :
            if visited[r][c] or board[r][c] == '.' : 
                continue
            if is_air(r,c) :
                cal_dist(r,c)
                return
            
d = False
for h in h_lst :
    bar(h,d)
    fall()
    d = not d
    
for s in board :
    print(''.join(s))
                    