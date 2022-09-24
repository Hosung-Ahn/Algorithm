import functools

def solution(m, n, puddles):
    MOD = 1_000_000_007
    puddle = [[0 for _ in range(m)] for _ in range(n)]
    for p in puddles :
        puddle[p[1]-1][p[0]-1] = -2
        
    def in_range(r,c) :
        if r<0 or r>=n or c<0 or c>=m : return False
        return True
        
    @functools.lru_cache()
    def find_dp(r, c) :
        if not in_range(r,c) or puddle[r][c] : return 0
        if r == 0 and c == 0 : return 1
        
        left = find_dp(r,c-1)
        up = find_dp(r-1,c)
        ret = (left+up) % MOD
        return ret
        
    return find_dp(n-1, m-1)

print(solution(4,3, [[2, 2]]))
 