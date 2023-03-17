
def find_dp(k, idx) :
    if idx < 0 : return 0
    if dp[k][idx] != -1 : return dp[k][idx]
    
    dp[k][idx] = arr[k][idx] + max(find_dp((k+1)%2, idx-1), find_dp((k+1)%2,idx-2))
    return dp[k][idx]
    

T = int(input())
for _ in range(T) :
    N = int(input()) 
    arr = []
    for _ in range(2) :
        arr.append(list(map(int, input().split())))
    dp = [[-1 for _ in range(N)] for _ in range(2)]
    
    print(max(find_dp(0,N-1), find_dp(1,N-1)))
    