import sys
sys.setrecursionlimit(100000)

def solution(tickets):
    visited = [False for _ in range(len(tickets))]
    tickets.sort(key=lambda x : x[1])
    arr = ['ICN']
    
    def dfs() :
        if all(visited) : return True
        cur = arr[-1]
        
        for i,next in enumerate(tickets) :
            if visited[i] or next[0] != cur : continue
            visited[i] = True
            arr.append(next[1])
            if dfs() : return True
            arr.pop(-1)
            visited[i] = False 
        
    
    dfs()
    
    return arr
        
        
print(solution([["ICN", "JFK"], ["HND", "IAD"], ["JFK", "HND"]]))
print(solution([["ICN", "SFO"], ["ICN", "ATL"], ["SFO", "ATL"], ["ATL", "ICN"], ["ATL", "SFO"]]))