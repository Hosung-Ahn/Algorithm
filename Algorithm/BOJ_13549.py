import heapq

MAX = 100_000
INF = 987654321

N,K = map(int, input().split())

dist = [INF for _ in range(MAX*2)]

def in_range(n) :
    if n < 0 or n >= MAX*2 : return False 
    return True

def dijkstra(s) :
    dist[s] = 0
    q = []
    heapq.heappush(q, [0, s])
    
    while q :
        cur_dist, cur_node = heapq.heappop(q)
        
        if dist[cur_node] < cur_dist: continue
        
        d = [[cur_node-1, cur_dist+1], [cur_node+1, cur_dist+1], [cur_node*2, cur_dist]]
        
        for next_node, next_dist in d :
            if in_range(next_node) and dist[next_node] > next_dist :
                dist[next_node] = next_dist
                heapq.heappush(q, [next_dist, next_node])
                
dijkstra(N)

print(dist[K])
        
        
    