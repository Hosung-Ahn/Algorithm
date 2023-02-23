import sys
sys.setrecursionlimit(1000000)

MAX = 1001
MOD = 10007

dp = [[-1 for _ in range(MAX)] for _ in range(MAX)]

def comb(n,k) :
    if n==k or k==0 : return 1
    if dp[n][k] != -1 : return dp[n][k]
    
    dp[n][k] = comb(n-1, k) + comb(n-1, k-1)
    dp[n][k] %= MOD
    return dp[n][k]

n,k = map(int, input().split())
print(comb(n,k))

