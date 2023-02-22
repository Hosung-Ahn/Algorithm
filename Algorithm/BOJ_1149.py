N = int(input())
cost = []
MAX = 1000

for _ in range(N) :
    cost.append(list(map(int, input().split())))
    
dp = [[-1 for _ in range(3)] for _ in range(MAX)]

def find_dp(idx, color) :
    if idx == N : return 0
    
    ret = dp[idx][color]
    if ret != -1 : return ret
    
    ret = 987654321
    
    for next_color in range(3) :
        if color == next_color : continue
        ret = min(ret, cost[idx][color] + find_dp(idx+1, next_color))
        
    dp[idx][color] = ret
    return ret
        
print(min(find_dp(0,0), find_dp(0,1), find_dp(0,2)))