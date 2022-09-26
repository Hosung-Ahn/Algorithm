import functools

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

mirror = [[0 for _ in range(N)] for _ in range(N)]

def in_range(r,c) :
    if r<0 or r>= N or c<0 or c>=N : return False
    return True

@functools.lru_cache(maxsize=None)
def move(r,c,d,cnt) :
    global ans
    if not in_range(r,c) or board[r][c] == '*' : return
    
    if board[r][c] == '#' and r != sr and c != sc :
        ans = min(ans, cnt)
        return
    
    elif board[r][c] == '.' : 
        return move(r+dr[d], c+dc[d], d, cnt)
    
    else :
        left = (d-1)%4
        right = (d+1)%4
        if mirror[r][c] == 0 :
            move(r+dr[d], c+dc[d], d, cnt)
            
            mirror[r][c] = 1
            move(r+dr[left], c+dc[left], left, cnt+1)
            mirror[r][c] = 0
            
            mirror[r][c] = 2
            move(r+dr[right], c+dc[right], right, cnt+1)
            mirror[r][c] = 0
            
        elif mirror[r][c] == 1 :
            move(r+dr[left], c+dc[left], left, cnt)
        elif mirror[r][c] == 2 :
            move(r+dr[right], c+dc[right], right, cnt)
        
for r in range(N) :
    for c in range(N) :
        if board[r][c] == '#' :
            sr = r
            sc = c
            break
        
for d in range(4) :
    move(sr+dr[d], sc+dc[d], d, 0)
        
print(ans)