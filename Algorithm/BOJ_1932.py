MAX = 500
dp = [[-1 for _ in range(MAX)] for _ in range(MAX)]

def find_dp(floor, idx) :
    if floor == N-1 :
        return triangle[floor][idx]
    
    if dp[floor][idx] != -1 : return dp[floor][idx]
    
    dp[floor][idx] = triangle[floor][idx] + max(find_dp(floor+1, idx), find_dp(floor+1, idx+1))
    
    return dp[floor][idx]

N = int(input())
triangle = []
for _ in range(N) :
    triangle.append(list(map(int, input().split())))

print(find_dp(0,0))