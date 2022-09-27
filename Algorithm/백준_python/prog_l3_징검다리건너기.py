def f(stones, n, k) :
    cnt = 0
    for stone in stones :
        if stone-n <= 0 : cnt += 1
        else : cnt = 0
        if cnt >= k : return True
    return False

def solution(stones, k):
    lo = 1
    hi = 200_000_000
    while lo < hi :
        mid = (lo+hi)//2 
        if f(stones, mid, k) :
            hi = mid
        else : lo = mid+1
    return lo

solution([2, 4, 5, 3, 2, 1, 4, 2, 5, 1], 3)