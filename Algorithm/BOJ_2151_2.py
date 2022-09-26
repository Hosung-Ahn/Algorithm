N = int(input())
board = []

for _ in range(N) :
    s = input()
    board.append(s)
    
ans = 987654321
dr = [-1,0,1,0]
dc = [0,1,0,-1]

sr = 0
sc = 0
er = 0
ec = 0

mirror = [[0 for _ in range(N)] for _ in range(N)]

def in_range(r,c) :
    if r<0 or r>= N or c<0 or c>=N : return False
    return True

def bfs() :
    global sr,sc,er,ec
    q = []
    visited = [[[False for _ in range(4)] for _ in range(50)] for _ in range(50)]
    for d in range(4) :
        visited[sr][sc][d] = True
        q.append([sr,sc,d,0])
        
    while q :
        cr = q[0][0]
        cc = q[0][1]
        cd = q[0][2]
        cnt = q[0][3]
        q.pop(0)
        
        left = (cd-1)%4
        right = (cd+1)%4
        
        while in_range(cr,cc) :
            if not visited[cr][cc][d] : 
                if board[cr][cc] == '*' : 
                    break
                elif board[cr][cc] == '!' :
                    visited[cr][cc][left] = True
                    q.append([cr,cc,left,cnt+1])
                    visited[cr][cc][right] = True
                    q.append([cr,cc,right,cnt+1])
                elif board[cr][cc] == '#' and cr == er and cc == ec :
                    return cnt
                
            cr += dr[cd]
            cc += dc[cd]
                
    
        

        
ck = False
for r in range(N) :
    for c in range(N) :
        if board[r][c] == '#' :
            if ck :
                er = r
                ec = c
                break
            else :
                sr = r
                sc = c
                ck = True
        
print(bfs())