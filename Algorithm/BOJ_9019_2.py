from sys import stdin
input = stdin.readline
from collections import deque

T = int(input())

def D(x) :
    return x*2 % 10000

def S(x) :
    if x == 0 : return 9999
    return x-1

def L(n):
      return 10 * (n % 1000) + n // 1000

def R(n):
  return 1000 * (n % 10) + n // 10

def bfs(s,e) :
    visited = [False for _ in range(10000)]
    visited[s] = True
    path = ['' for _ in range(10000)]
    q = deque([s])
    while q :
        cur_node = q.popleft()
        
        if cur_node == e :
            print(path[cur_node])
            return
        
        for f, op in zip([D,S,L,R], ['D','S','L','R']) :
            next_node = f(cur_node)
            if visited[next_node] : continue
            visited[next_node] = True
            path[next_node] = path[cur_node] + op
            q.append(next_node)
            
for _ in range(T) :
    s,e = map(int, input().split())
    bfs(s,e)
