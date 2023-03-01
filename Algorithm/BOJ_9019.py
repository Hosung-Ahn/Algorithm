from sys import stdin
input = stdin.readline
from collections import deque

T = int(input())

def D(x) :
    return x*2 % 10000

def S(x) :
    if x == 0 : return 9999
    return x-1

def L(x) :
    x = f"{x:0>4}"
    return int(x[1:] + x[0])

def R(x) :
    x = f"{x:0>4}"
    return int(x[-1] + x[:-1])

def RD1(x) :
    return x//2

def RD2(x) :
    return (x+10000)//2

def RS(x) :
    return (x+1) % 10000

def bfs(s,e) :
    visited = [[-1, ''] for _ in range(10000)]
    visited[s] = [0, '']
    visited[e] = [1, '']
    q = deque([[s, 0], [e, 1]])
    while q :
        cur_node, cur_type = q.popleft()
        cur_path = visited[cur_node][1]
        
        if cur_type == 0 :
            for f, op in zip([D,S,L,R], ['D','S','L','R']) :
                next_node, next_path = f(cur_node), cur_path+op
                next_type, reverse_path = visited[next_node]
                if next_type == -1 :
                    visited[next_node] = [cur_type, next_path]
                    q.append([next_node, cur_type])
                elif next_type == 0 : continue
                else :
                    print(next_path + reverse_path)
                    return
        else :
            for f, op in zip([RD1, RD2, RS, R, L], ['D','D','S','L','R']) :
                next_node, next_path = f(cur_node), op+cur_path
                next_type, reverse_path = visited[next_node]
                
                if cur_node % 2 == 1 and op == 'D' : continue
                
                if next_type == -1 :
                    visited[next_node] = [cur_type, next_path]
                    q.append([next_node, cur_type])
                elif next_type == 1 : continue
                else :
                    print(reverse_path+next_path)
                    return
        
    
for _ in range(T) :
    s,e = map(int, input().split())
    bfs(s,e)
