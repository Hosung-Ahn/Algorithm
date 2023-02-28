INF = 987654321
V,E = map(int, input().split())

dist = [[0 if i==j else INF for i in range(V+1)] for j in range(V+1)]

for _ in range(E) :
    a,b,c = map(int, input().split())
    dist[a][b] = 0
    dist[b][a] = 0 if c==1 else 1
    
def floyd() :
    for m in range(1,V+1) :
        for s in range(1,V+1) :
            for e in range(1,V+1) :
                dist[s][e] = min(dist[s][e], dist[s][m]+dist[m][e])
                
floyd()

K = int(input())

for _ in range(K) :
    a,b = map(int, input().split())
    print(dist[a][b])
    


