import sys
from queue import Queue
input = sys.stdin.readline

R,C = map(int, input().split())
board = []
for _ in range(R) :
    s = list(input())
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
            for nr in range(r+1,R) :
                if local_visited[nr][c] : return 1000
                if board[nr][c] == 'x' : break
            ret = 0
            while(r < R-1 and board[r+1][c] == '.') :
                r += 1
                ret += 1
            return ret
    
        ret = 1000
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
                
        for r in range(R) : 
            for c in range(C) :
                if local_visited[r][c] :
                    ret = min(ret, tmp_dist(r,c))
        return ret
    
    def move(r,c, dist) :
        copy_board = [[False for _ in range(C)] for _ in range(R)]
        local_visited = [ [False for _ in range(C)] for _ in range(R) ]
        q = Queue()
        q.put([r,c])
        local_visited[r][c] = True
        while(not q.empty()) :
            cr,cc = q.get()
            board[cr][cc] = '.'
            copy_board[cr+dist][cc] = True
            for i in range(4) :
                nr = cr + dr[i]
                nc = cc + dc[i]
                if not in_range(nr, nc) or local_visited[nr][nc] or board[nr][nc] == '.':
                    continue
                local_visited[nr][nc] = True
                q.put([nr,nc])
                
        for r in range(R) :
            for c in range(C) :
                if copy_board[r][c] :
                    board[r][c] = 'x'
    
    for r in range(R) :
        for c in range(C) :
            if visited[r][c] or board[r][c] == '.' : 
                continue
            if is_air(r,c) :
                dist = cal_dist(r,c)
                move(r,c,dist)
                return
            
d = False
for h in h_lst :
    bar(h,d)
    fall()
    d = not d
    
for s in board :
    print(''.join(s), end = '')
                    