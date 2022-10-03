import sys
sys.setrecursionlimit(100000)

def solution(enroll, referral, seller, amount):
    hashing = dict()
    hashing['-'] = 0
    for i, name in enumerate(enroll,1) :
        hashing[name] = i
    
    edges = [[] for _ in range(len(enroll)+1)]
    result = [0 for _ in range(len(enroll)+1)]
    
    for i in range(len(edges)) :
        edges[i] = list(set(edges[i]))
    
    for i, name in enumerate(seller) :
        result[hashing[name]] += amount[i]*100
        
    for i,name in enumerate(referral,1) :
        edges[hashing[name]].append(i)
        
    def dfs(cur) :
        for nxt in edges[cur] :
            result[cur] += dfs(nxt)//10
        ret = result[cur]
        result[cur] -= result[cur]//10
        return ret
    
    dfs(0)
    
    return result[1:]
        
    
print(solution(["john", "mary", "edward", "sam", "emily", "jaimie", "tod", "young"],
               ["-", "-", "mary", "edward", "mary", "mary", "jaimie", "edward"], 
               ["young", "john", "tod", "emily", "mary", "john", 'young'], 
               [12, 4, 2, 5, 10,3,1]))
