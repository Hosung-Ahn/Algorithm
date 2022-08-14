h,w = map(int,input().split())

m = []
for i in range(h+1) :
    m.append([])
    for j in range(w+1) :
        m[i].append(0)
        
n = int(input())

for i in range(n) :
    l,d,x,y = map(int,input().split())
    if d == 1 :
        for i in range(l) :
            m[x+i][y] = 1
    else :
        for i in range(l) :
            m[x][y+i] = 1
            
for i in range(1, h+1) :
    for j in range(1, w+1) :
        print(m[i][j], end=' ')
    print()