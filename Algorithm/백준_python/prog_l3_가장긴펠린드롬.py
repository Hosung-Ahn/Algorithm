import functools

def solution(s):
    ans = 0
    @functools.lru_cache(maxsize=None)
    def find_dp(l,r) :
        nonlocal ans
        if r-l+1 <= 1 : return True
        if s[l] == s[r] and find_dp(l+1,r-1):
            ans = max(ans,r-l+1)
            return True
        else : 
            find_dp(l+1,r)
            find_dp(l,r-1)
            return False
            
    find_dp(0,len(s)-1)
    return ans
    
    
    