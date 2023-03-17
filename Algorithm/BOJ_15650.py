N,M = map(int, input().split())

def C(i, k, ans) :
    if k == 0 : 
        print(*ans)
    for n in range(i, N+1) :
        ans.append(n)
        C(n+1,k-1,ans)
        ans.pop(-1)
    
C(1, M, [])