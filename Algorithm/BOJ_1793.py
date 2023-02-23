MAX = 251
dp = [-1 for _ in range(MAX)]

def find_dp(n) :
    if n == 0 : return 1
    if n == 1 : return 1
    if n == 2 : return 3
    
    if dp[n] != -1 : return dp[n]
    dp[n] = find_dp(n-1) + 2*find_dp(n-2)
    return dp[n]
    

while 1 :
    try :
        n = int(input())
    except :
        break
    print(find_dp(n))