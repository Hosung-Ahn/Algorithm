def f(t, times) : 
    ret = 0
    for time in times :
        ret += t // time
    return ret

def under_bs(n, times) :
    lo = 1
    hi = 1_000_000_000
    
    while lo < hi :
        mid = (lo+hi)//2
        tmp = f(mid, times)
        if tmp < n :
            lo = mid + 1
        else :
            hi = mid
    
    return lo


def solution(n, times):
    return under_bs(n, times)

print(solution(6, [1]))
