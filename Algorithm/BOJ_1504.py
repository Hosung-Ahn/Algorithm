import heapq
INF = 987654321

V,E = map(int, input().split())
edges = [[] for _ in range(V+1)]

for _ in range(E) :
    a,b,c = map(int, input().split())
    edges[a].append([b,c])
    edges[b].append([a,c])
    
A,B = map(int, input().split())
    
def dijkstra(s, e) :
    dist = [INF for _ in range(V+1)]
    dist[s] = 0
    q = []
    heapq.heappush(q, [0,s])
    while q :
        cur_dist, cur_node = heapq.heappop(q)
        
        if dist[cur_node] < cur_dist : continue
        
        for next_node, c in edges[cur_node] :
            next_dist = cur_dist + c
            if dist[next_node] <= next_dist : continue
            dist[next_node] = next_dist
            heapq.heappush(q, [next_dist, next_node])
            
    return dist[e]

ans = min(dijkstra(1,A) + dijkstra(A,B) + dijkstra(B,V), dijkstra(1,B) + dijkstra(B,A) + dijkstra(A,V))
print(-1 if ans >= INF else ans)