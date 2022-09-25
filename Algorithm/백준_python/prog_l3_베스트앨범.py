from collections import defaultdict

def solution(genres, plays):
    N = len(genres)
    dic = defaultdict(list)
    for i in range(N) :
        dic[genres[i]].append([plays[i],i])
        
    def cmp(key) :
        ret = 0
        for a,b in dic[key] :
            ret += a
        return -ret
    
    keys = sorted(dic.keys(), key=cmp)
    ans = []
    for key in keys :
        arr = sorted(dic[key], key=lambda x : (-x[0],x[1]))
        for a,b in arr[:2] :
            ans.append(b)
            
    return ans
    
    
        
print(solution(["classic", "pop", "classic", "classic", "pop"], [500, 600, 150, 800, 2500]))
