V,E = map(int, input().split())
gender = ['-1']
gender.extend(input().split()) 
edges = []
SET = [i for i in range(V+1)]

for _ in range(E) :
    edges.append(list(map(int, input().split())))
    
edges.sort(key=lambda x : x[2])

def get_parent(n) :
    if n == SET[n] : return n
    SET[n] = get_parent(SET[n])
    return SET[n]

def is_set(a,b) :
    a = get_parent(a)
    b = get_parent(b)
    return a == b

def union(a,b) :
    a = get_parent(a)
    b = get_parent(b)
    if a < b : SET[b] = a
    else : SET[a] = b
    
ans = 0
cnt = 0
for edge in edges :
    a,b,c = edge
    if gender[a] != gender[b] and not is_set(a,b) :
        ans += c
        cnt += 1
        union(a,b)
        
print(-1 if cnt < V-1 else ans)

