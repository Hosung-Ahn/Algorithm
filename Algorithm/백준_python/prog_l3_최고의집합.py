def solution(n, s):
    if n < s :
        return [-1]
    
    ret = []
    while n :
        x = s//n
        s -= x
        n -= 1
        ret.append(x)
        
    return ret


        