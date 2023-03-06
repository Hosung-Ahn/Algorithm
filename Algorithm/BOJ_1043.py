from collections import deque

N,M = map(int, input().split())

people = list(map(int, input().split()))[1:]
SET = [i for i in range(N+1)]
parties = []
edges = [[] for _ in range(N+1)]

for i in range(M) :
    arr = list(map(int, input().split()))[1:]
    parties.append(arr)
    for a in arr :
        edges[a].append(i)
    
def bfs() :
    q = deque(people)
    visited = [False for _ in range(M)]
    while q :
        cur = q.popleft()
        for next_party in edges[cur] :
            if visited[next_party] : continue
            visited[next_party] = True
            for p in parties[next_party] :
                q.append(p)
                
    print(M-sum(visited))
    
bfs()
            