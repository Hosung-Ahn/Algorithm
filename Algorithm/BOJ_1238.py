import heapq
MAX = 1001
INF = 987654321

edges = [[] for _ in range(MAX)]
dist = [[INF for _ in range(MAX)] for _ in range(MAX)]

v,e,x = map(int, input().split())

for _ in range(e) :
    a,b,c = map(int, input().split())
    edges[a].append([b,c])
    
def dijkstra(s) :
    q = []
    heapq.heappush(q, [0, s])
    dist[s][s] = 0
    
    while q :
        cur_dist, cur_node = heapq.heappop(q)
        if dist[s][cur_node] < cur_dist : continue
        
        for next_node, c in edges[cur_node] :
            next_dist = cur_dist + c
            if dist[s][next_node] <= next_dist : continue
            dist[s][next_node] = next_dist
            heapq.heappush(q, [next_dist, next_node])
            
            
for n in range(1, v+1) :
    dijkstra(n)
ans = -1
for n in range(1,v+1) :
    ans = max(ans, dist[n][x] + dist[x][n])
    

print(ans)