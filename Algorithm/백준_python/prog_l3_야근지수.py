import bisect

def solution(n, works):
    works.sort()
    
    while n :
        x = works[-1]
        if x == 0 :
            break
        works.pop(-1)
        bisect.insort(works, x-1)
        n -= 1
        
    ans = 0
    for a in works :
        ans += a**2
        
    return ans
        
    
        