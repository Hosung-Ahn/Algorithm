from queue import PriorityQueue

MAX = 152
INF = 987654321

def solution(alp, cop, problems):
    pq = PriorityQueue()
    pq.put([0, alp, cop])
    dist = [[INF for _ in range(MAX)] for _ in range(MAX)]
    dist[alp][cop] = 0
    
    FX = 0
    FY = 0
    for prob in problems :
        FX = max(FX, prob[0])
        FY = max(FY, prob[1])
        
    ans = INF
    
    while not pq.empty() :
        cur = pq.get()
        cd = cur[0]
        cx = cur[1]
        cy = cur[2]
        
        if dist[cx][cy] < cd : continue 
        
        if cx >= FX and cy >= FY :
            ans = min(ans, dist[cx][cy])
            continue
    
        for p in problems :
            if p[2] == 0 and p[3] == 0 : continue
            if cx >= p[0] and cy >= p[1] :
                nx = min(cx + p[2], 151)
                ny = min(cy + p[3], 151)
                if dist[nx][ny] > cd + p[4] :
                    dist[nx][ny] = cd + p[4]
                    pq.put([cd+p[4], nx, ny])
                    
        if cx < FX and dist[cx+1][cy] > cd + 1 :
            dist[cx+1][cy] = cd + 1
            pq.put([cd+1, cx+1,cy])
        if cy < FY and dist[cx][cy+1] > cd + 1 :
            dist[cx][cy+1] = cd + 1
            pq.put([cd+1, cx, cy+1])
                    
    return ans

    
print(solution(10,10,	[[10,15,2,1,2],[20,20,3,3,4]]))