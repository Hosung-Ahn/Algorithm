def solution(n, costs):
    set_num = [i for i in range(n)]
    costs.sort(key=lambda x : x[2])
    
    def get_parent(a) :
        if a==set_num[a] : return a
        set_num[a] = get_parent(set_num[a])
        return set_num[a]
    
    def union_num(a,b) :
        a = get_parent(a)
        b = get_parent(b)
        
        if a < b : set_num[b] = a
        else : set_num[a] = b
        
    def is_set(a,b) :
        a = get_parent(a)
        b = get_parent(b)
        return a==b
    
    ans = 0
    for cost in costs : 
        a = cost[0]
        b = cost[1]
        d = cost[2]
        if is_set(a,b) : continue
        union_num(a,b)
        ans += d
        print(set_num)
        
    return ans