import heapq
INF = 987654321

N, E = map(int, input().split())
edges = [[] for _ in range(N+1)]
dist = [INF for _ in range(N+1)]

for _ in range(E) :
    a,b,c = map(int, input().split())
    edges[a].append([b,c])
    edges[b].append([a,c])
    
def dijkstra() :
    dist[1] = 0
    q = []
    heapq.heappush(q, [0,1])
    
    while q :
        cur_dist, cur_node = heapq.heappop(q)
        
        if dist[cur_node] < cur_dist : continue
        
        for next_node, c in edges[cur_node] :
            next_dist = cur_dist + c
            if dist[next_node] <= next_dist : continue
            dist[next_node] = next_dist
            heapq.heappush(q, [next_dist, next_node])
            
dijkstra()

print(dist[N])