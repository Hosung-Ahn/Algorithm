def solution(routes):
    ans = 0    
    routes.sort(key = lambda x : x[1])
    
    e = -50000
    
    for route in routes :
        ns = route[0]
        ne = route[1]
        if ns > e :
            e = ne
            ans += 1
            
    return ans