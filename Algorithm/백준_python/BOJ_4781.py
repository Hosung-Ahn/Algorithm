import sys
import functools
input = sys.stdin.readline

sys.setrecursionlimit(100000)

def solve() :

    N, total = map(float, input().split())
    N = int(N)
    total = int(total*100 + 0.5)
    if N == 0 and total == 0 : return False
    arr = []
    for _ in range(N) :
        c, m = map(float, input().split()) 
        arr.append([int(c),int(m*100 + 0.5)])
        
    arr.sort(key = lambda x : x[1])

    @functools.lru_cache(maxsize=None)
    def find_dp(money) :
        ret = 0
        for c,m in arr :
            if money < m : break
            ret = max(ret, c + find_dp(money-m))
        return ret
    
    print(find_dp(total))
    return True

while solve() :
    pass