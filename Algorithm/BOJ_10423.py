V,E,K = map(int, input().split())
is_elect = [False for _ in range(V+1)]
SET = [i for i in range(V+1)]

arr = map(int, input().split())
for a in arr :
    is_elect[a] = True
    
edges = []
for _ in range(E) :
    edges.append(list(map(int, input().split())))    
edges.sort(key = lambda x : x[2])

def get_parent(n) :
    if n == SET[n] : return n
    SET[n] = get_parent(SET[n])
    return SET[n]

def is_set(a,b) :
    a = get_parent(a)
    b = get_parent(b)
    return a == b

def is_all_elect(a,b) :
    a = get_parent(a)
    b = get_parent(b)
    return is_elect[a] and is_elect[b]

def union(a,b) :
    a = get_parent(a)
    b = get_parent(b)
    if not is_elect[a] and not is_elect[b] :
        if a < b : SET[b] = a
        else : SET[a] = b
    else :
        if is_elect[a] : SET[b] = a
        else : SET[a] = b
        
ans = 0
        
for edge in edges :
    a,b,c = edge
    if is_all_elect(a,b) or is_set(a,b) : continue
    union(a,b)
    ans += c
        
print(ans)