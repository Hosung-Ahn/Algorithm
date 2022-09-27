from collections import defaultdict

def solution(n, edge):
    edges = [[] for _ in range(n+1)]
    dist = defaultdict(int)
    
    for a,b in edge :
        edges[a].append(b)
        edges[b].append(a)

    def bfs() :
        visited = [False for _ in range(n+1)]
        visited[1] = True
        q = [[1,0]]
        while q :
            c = q[0][0]
            d = q[0][1]
            q.pop(0)
            
            dist[d] += 1
            
            for next in edges[c] :
                if visited[next] : continue
                visited[next] = True
                q.append([next,d+1])
        
    bfs()
    mk = max(dist.keys())
    print(dist)
    return dist[mk]
