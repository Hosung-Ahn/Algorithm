import functools

N,K = map(int, input().split())
arr = []
for _ in range(N) :
    a = int(input())
    arr.append(a)
    
sum_arr = [0]
s = 0
for a in arr :
    s += a
    sum_arr.append(s)

def cal_sum(s,e) :
    return sum_arr[e+1]-sum_arr[s]

INF = -987654321

@functools.lru_cache(maxsize=None)
def find_dp(s,k) :
    if k == K : return 0
    if s >= N : return INF
    ret = find_dp(s+1,k)
    for e in range(s, N) :
        ret = max(ret, cal_sum(s,e)+find_dp(e+2,k+1))
    return ret

print(find_dp(0,0))
    