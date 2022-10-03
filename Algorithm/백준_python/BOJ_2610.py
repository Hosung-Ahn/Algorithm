import sys
input = sys.stdin.readline

N = int(input())
M = int(input())
INF = 987654321

dist = [[INF for _ in range(N+1)] for _ in range(N+1)]
SET = [i for i in range(N+1)]

for n in range(N+1) :
    dist[n][n] = 0
    
def get_parent(a) :
    if a == SET[a] : return a
    SET[a] = get_parent(SET[a])
    return SET[a]

def union(a, b) :
    a = get_parent(a)
    b = get_parent(b)
    if a < b : SET[b] = a
    else : SET[a] = b
    
for _ in range(M) :
    a,b = map(int, input().split())
    dist[a][b] = 1 
    dist[b][a] = 1
    union(a,b)
    
map(get_parent, SET)
print(len(set(SET[1:])))

set_arr = [[] for _ in range(N+1)]

for a, s in enumerate(SET[1:], 1) :
    set_arr[s].append(a)
    
def floyd() :
    for m in range(1,N+1) :
        for s in range(1,N+1) :
            if s == m : continue
            for e in range(1,N+1) :
                if e == m or e == s : continue
                dist[s][e] = min(dist[s][e], dist[s][m]+dist[m][e])
                
floyd()

def find_boss(arr) :
    max_dist = INF
    ret = -1
    for a in arr :
        tmp = 0
        for b in arr :
            tmp = max(tmp,dist[b][a])
        if tmp < max_dist :
            ret = a
            max_dist = tmp
    return ret

ans = []

for arr in set_arr :
    if len(arr) == 0 : continue
    ans.append(find_boss(arr))
    
ans.sort()

for a in ans :
    print(a)