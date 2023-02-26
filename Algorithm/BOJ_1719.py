import heapq
INF = 987654321

V,E = map(int, input().split())

edges = [[] for _ in range(V+1)]
ans = [[0 for _ in range(V+1)] for _ in range(V+1)]

for _ in range(E) :
    a,b,c = map(int, input().split())
    edges[a].append([b,c])
    edges[b].append([a,c])
    
def dijkstra(s) :
    q = []
    dist = [INF for _ in range(V+1)]
    dist[s] = 0
    
    for next_node, c in edges[s] :
        heapq.heappush(q, [c, next_node, next_node])
        dist[next_node] = c
        ans[s][next_node] = next_node
        
    while q :
        cur_dist, cur_node, start_node = heapq.heappop(q)
        
        if dist[cur_node] < cur_dist : continue
        
        for next_node, c in edges[cur_node] :
            next_dist = cur_dist + c
            if dist[next_node] <= next_dist : continue
            dist[next_node] = next_dist
            ans[s][next_node] = start_node
            heapq.heappush(q, [next_dist, next_node, start_node])
            
for n in range(1, V+1) :
    dijkstra(n)
    
for i in range(1, V+1) :
    for j in range(1, V+1) :
        x = '-' if i == j else ans[i][j]
        print(x, end = ' ')
    print()
            
        
        
    