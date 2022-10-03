import sys
input = sys.stdin.readline

N,M,k = map(int, input().split())
arr = list(map(int, input().split()))

S = [i for i in range(N+1)]

def get_parent(a) :
    if a == S[a] : return a
    S[a] = get_parent(S[a])
    return S[a]

def union(a, b) :
    a = get_parent(a)
    b = get_parent(b)
    
    if arr[a-1] < arr[b-1] :    
        S[b] = a
    else :
        S[a] = b
        
def is_set(a,b) :
    a = get_parent(a)
    b = get_parent(b)
    return a == b

for _ in range(M) :
    a,b = map(int, input().split())
    union(a,b)

S = list(set(map(get_parent, S[1:])))
ans = 0
for s in S :
    ans += arr[s-1]

if ans > k :
    print('Oh no')
else : print(ans)

