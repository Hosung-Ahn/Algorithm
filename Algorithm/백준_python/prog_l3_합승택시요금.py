INF = 9876543210
dist = [[INF for _ in range(201)] for _ in range(201)]

def floyd(n) :
    for i in range(1,n+1) :
        dist[i][i] = 0
    
    for m in range(1, n+1) :
        for s in range(1,n+1) :
            if s == m : continue
            for e in range(1,n+1) :
                if e == m or e == s : continue
                dist[s][e] = min(dist[s][e],dist[s][m]+dist[m][e])
                
    

def solution(n, s, a, b, fares):
    
    for q,w,d in fares :
        dist[q][w] = d
        dist[w][q] = d
        
    floyd(n)
    ans = INF
    
    for m in range(1,n+1) :
        ans = min(ans, dist[s][m] + dist[m][a] + dist[m][b])
    return ans