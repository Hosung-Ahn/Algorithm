import heapq

INF = 987654321
MAX = 20001

V,E = map(int, input().split())
S = int(input())

edges = [[] for _ in range(MAX)]
dist = [INF for _ in range(MAX)]

def dijkstra(start) :
    dist[start] = 0
    q = []
    heapq.heappush(q, [0, start])
    
    while q :
        cur_dist, cur_node = heapq.heappop(q)
        if dist[cur_node] < cur_dist : continue
        
        for next_node, c in edges[cur_node] :
            next_dist = cur_dist + c
            if dist[next_node] <= next_dist : continue
            dist[next_node] = next_dist
            heapq.heappush(q, [next_dist, next_node])

for _ in range(E) : 
    a,b,c = map(int, input().split())
    edges[a].append([b,c])

dijkstra(S)

for n in range(1, V+1) :
    if dist[n] == INF : print('INF')
    else : print(dist[n])




