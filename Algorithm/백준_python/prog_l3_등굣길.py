def solution(m, n, puddles):
    dp = [[-1 for _ in range(m)] for _ in range(n)]
    MOD = 1_000_000_007
    for p in puddles :
        dp[p[1]][p[0]] = -2
        
    def in_range(r,c) :
        if r<0 or r>=n or c<0 or c>=m : return False
        return True
        
    def find_dp(r, c) :
        nonlocal dp
        if not in_range(r,c) or dp[r][c] == -2: return 0
        if r == 0 and c == 0 : return 1
        if dp[r][c] != -1 : return dp[r][c]
        
        left = find_dp(r,c-1)
        up = find_dp(r-1,c)
        ret = (left+up) % MOD
        dp[r][c] = ret
        return ret
        
        
    x = find_dp(n-1, m-1)
    for r in range(3) :
        for c in range(4) :
            print(dp[r][c], end = ' ')
        print()
    return x

print(solution(4,3, [[2, 2]]))
 