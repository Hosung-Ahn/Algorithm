
    

def solution(n, computers):
    visited = [False for _ in range(n)]
    def bfs(s) :
        nonlocal visited
        visited[s] = True
        q = [s]
        while q :
            cur = q[0]
            q.pop(0)
            
            for next in range(n) :
                if computers[cur][next] == 0 or visited[next] : continue
                visited[next] = True
                q.append(next)
    
    ans = 0
    for s in range(n) :
        if visited[s] : continue
        bfs(s)
        ans += 1
        
    return ans