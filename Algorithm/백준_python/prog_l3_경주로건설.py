def solution(board):
    INF = 987654321
    visited = [[[INF for _ in range(4)] for _ in range(25)] for _ in range(25)]
    dr = [-1,0,1,0]
    dc = [0,1,0,-1]
    
    N = len(board)
    
    def in_range(r, c) :
        if r<0 or r>=N or c<0 or c>= N : return False
        return True
    
    def bfs() :
        q = []
        for i in range(4) :
            r = dr[i]
            c = dc[i]
            if not in_range(r, c) or board[r][c] == 1: continue
            q.append([r,c,i])
            visited[r][c][i] = 100
        
        while q :
            cr = q[0][0]
            cc = q[0][1]
            cd = q[0][2]
            q.pop(0)
            print(cr,cc,cd, visited[cr][cc][cd])
            
            for d in range(4) :
                nr = cr+dr[d]
                nc = cc+dc[d]
                if not in_range(nr,nc) or board[nr][nc] == 1: continue
                if (d+2)%4 == cd : continue
                cost = visited[cr][cc][cd]
                
                if d == cd : cost += 100
                else : cost += 600
                
                if visited[nr][nc][d] <= cost : continue
                visited[nr][nc][d] = cost
                q.append([nr,nc,d])
    
    bfs()
    
    return min(visited[N-1][N-1])

      