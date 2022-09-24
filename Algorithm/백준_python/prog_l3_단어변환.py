def solution(begin, target, words):
    
    def can_jump(s1, s2) :
        cnt = 0
        for i in range(len(s1)) :
            if s1[i] != s2[i] : cnt += 1
            
        return cnt == 1
    
    
    def bfs() :
        visited = [0 for _ in range(len(words))]
        q = []
        for i, word in enumerate(words) :
            if can_jump(begin, word) :
                q.append(i)
                visited[i] = 1
                
        while q :
            cur = q.pop(0)
            if words[cur] == target :
                return visited[cur]
            for next, word in enumerate(words) :
                if visited[next] or not can_jump(words[cur], word) : continue
                visited[next] = visited[cur] + 1
                q.append(next)
        
        return 0
    
    return bfs()