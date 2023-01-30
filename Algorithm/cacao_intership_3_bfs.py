def solution(alp, cop, problems):
    q = []
    q.append([alp, cop])
    INF = 987654321
    MAX = 152
    visited = [[INF for _ in range(MAX)] for _ in range(MAX)]
    visited[alp][cop] = 0
    
    FX = 0
    FY = 0
    for prob in problems :
        FX = max(FX, prob[0])
        FY = max(FY, prob[1])
        
    ans = INF
    
    while q :
        cx = q[0][0]
        cy = q[0][1]
        q.pop(0)
        
        if cx >= FX and cy >= FY :
            ans = min(ans, visited[cx][cy])
            continue
        
        for prob in problems :
            if prob[2] == 0 and prob[3] == 0 : continue
            
            if cx >= prob[0] and cy >= prob[1] :
                nx = min(cx + prob[2], 151)
                ny = min(cy + prob[3], 151)
                if visited[nx][ny] > visited[cx][cy] + prob[4] :
                    visited[nx][ny] = visited[cx][cy] + prob[4]
                    q.append([nx,ny])
        
        if cx < FX and visited[cx+1][cy] > visited[cx][cy]+1:
            visited[cx+1][cy] = visited[cx][cy]+1
            q.append([cx+1,cy])
            
        if cy < FY and visited[cx][cy+1] > visited[cx][cy]+1:
            visited[cx][cy+1] = visited[cx][cy]+1
            q.append([cx,cy+1])
                
                
    
    return ans

