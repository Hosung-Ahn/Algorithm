import math

def cal(length, w) : 
    return math.ceil(length/(2*w+1))

def solution(n, stations, w):
    ans = 0
    s = 1
    for station in stations :
        e = station-w-1
        length = e-s+1
        s = station+w+1
        if length <= 0 : continue
        ans += cal(length, w)
        
    if s <= n :
        length = n-s+1
        ans += cal(length, w)
    return ans


# print(solution(3,[2],1))
