def solution(A, B):
    idx = 0
    ans = 0
    
    N = len(A)
    A.sort()
    B.sort()
    
    for a in A :
        while idx < N and a >= B[idx] :
            idx += 1
        if idx == N : continue
        else : 
            ans += 1
            idx += 1
        
    return ans