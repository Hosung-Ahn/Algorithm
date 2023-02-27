import heapq

INF = 987654321

V = int(input())
E = int(input())

edges = [[INF if i != j else 0 for i in range(V+1)] for j in range(V+1)]
ans = [[INF for _ in range(V+1)] for _ in range(V+1)]

for _ in range(E) :
    a,b,c = map(int, input().split())
    edges[a][b] = min(edges[a][b], c)
    
def dijkstra(n) :
    q = []
    heapq.heappush(q, [0, n])
    
    while q :
        cur_dist, cur_node = heapq.heappop(q)
        if ans[n][cur_node] < cur_dist : continue
        
        for next_node in range(1,V+1) :
            if edges[cur_node][next_node] == INF : continue
            next_dist = cur_dist + edges[cur_node][next_node]
            if ans[n][next_node] <= next_dist : continue
            ans[n][next_node] = next_dist
            heapq.heappush(q, [next_dist, next_node])
            
for n in range(1, V+1) :
    dijkstra(n)
    
for i in range(1,V+1) :
    for j in range(1,V+1) :
        x = 0 if ans[i][j] >= INF else ans[i][j]
        print(x, end = ' ')
    print()
    

