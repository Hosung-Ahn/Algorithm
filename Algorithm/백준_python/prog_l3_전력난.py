import sys
input = sys.stdin.readline

S = []

def get_parent(a) :
    if a == S[a] : return a
    S[a] = get_parent(S[a])
    return S[a]

def union(a, b) : 
    a = get_parent(a)
    b = get_parent(b)
    
    if a < b : S[b] = a
    else : S[a] = b
    
def is_set(a, b) :
    a = get_parent(a) 
    b = get_parent(b)
    return a==b



def solve() :
    global S
    N,M = map(int, input().split())
    S = [i for i in range(N)]
    if N == 0 and M == 0 : return False
    
    edges = []
    for _ in range(M) :
        a,b,d = map(int, input().split())
        edges.append([a,b,d])
    edges.sort(key = lambda x : x[2])
    
    ans = 0
    SUM = 0
    for a,b,d in edges :
        SUM += d
        if is_set(a,b) : continue
        union(a,b)
        ans += d
        
    print(SUM-ans)
    return True 

while solve() :
    pass