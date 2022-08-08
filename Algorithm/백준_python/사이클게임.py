import sys

input = sys.stdin.readline

n,m = map(int, input().split())

SET = [i for i in range(n)]

def get_parent(a) :
    if SET[a] == a : return a
    SET[a] = get_parent(SET[a])
    return SET[a]

def union_node(a,b) :
    a = get_parent(a)
    b = get_parent(b)
    
    if a < b :
        SET[b] = a
    else :
        SET[a] = b

def same_set(a,b) :
    a = get_parent(a)
    b = get_parent(b)
    return a == b

ans = 0
check_point = True

for i in range(m) :
    a,b = map(int, input().split())
    if same_set(a,b) and check_point :
        ans = i+1
        check_point = False
    union_node(a,b)
    
print(ans)