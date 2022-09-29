import functools

def solution(sticker):
    
    @functools.lru_cache(maxsize=None)
    def find_dp(s) :
        l = len(sticker)-s
        if l <= 0 : return 0
        if l == 1 : return sticker[s]
        return max(sticker[s] + find_dp(s+2), find_dp(s+1))
    
    zero_out = find_dp(1)
    find_dp.cache_clear()
    if len(sticker) == 1 :
        zero_in = sticker[0]
    else :
        sticker.pop(-1)
        zero_in = sticker[0] + find_dp(2)
    
    print(zero_out, zero_in)
    return max(zero_in, zero_out)
        
print(solution([5, 1, 16, 17, 16]))