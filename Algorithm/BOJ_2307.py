import heapq
INF = 987654321

V,E = map(int, input().split())

edges = [[] for _ in range(V+1)]
path = [0 for _ in range(V+1)]

for _ in range(E) :
    a,b,c = map(int, input().split())
    edges[a].append([b,c])
    edges[b].append([a,c])
    
def dijkstra(a,b) :
    dist = [INF for _ in range(V+1)]
    dist[1] = 0
    q = []
    heapq.heappush(q, [0, 1])
    
    while q :
        cur_dist, cur_node = heapq.heappop(q)
        if dist[cur_node] < cur_dist : continue
        
        for next_node, c in edges[cur_node] :
            if (cur_node == a and next_node == b) or (cur_node == b and next_node == a) :
                continue
            next_dist = cur_dist + c
            
            if dist[next_node] <= next_dist : continue
            dist[next_node] = next_dist
            
            if a == -1 and b == -1 :
                path[next_node] = cur_node

            heapq.heappush(q, [next_dist, next_node])
            
    return dist[V]

start = dijkstra(-1,-1)
ans = 0

a = 1
b = V 
while a != b :
    tmp = dijkstra(path[b], b)
    if tmp == INF :
        ans = -1
        break
    ans = max(ans, tmp-start)
    b = path[b]
        
print(ans)