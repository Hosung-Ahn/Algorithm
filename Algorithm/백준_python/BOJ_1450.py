import functools

N,T = map(int, input().split())
arr = list(map(int, input().split()))
arr.sort()

@functools.lru_cache(maxsize=None)
def find_dp(idx, T) :
    if T < 0 : return 0
    if idx == N : return 1
    return find_dp(idx+1, T) + find_dp(idx+1, T-arr[idx])

print(find_dp(0,T))
    
    

