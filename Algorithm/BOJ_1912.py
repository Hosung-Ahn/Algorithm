from sys import stdin
input = stdin.readline

N = int(input())
MAX = 100_000

arr = list(map(int, input().split()))
dp = [-2000 for _ in range(MAX)]

def find_dp(idx) :
    if idx == 0 : return arr[idx]
    
    ret = dp[idx]
    if ret != -2000 : return ret
    
    ret = arr[idx]
    if find_dp(idx-1) > 0 : ret += find_dp(idx-1)
    dp[idx] = ret
    return ret

ans = -2000
for i in range(N) :
    ans = max(ans, find_dp(i))
print(ans)