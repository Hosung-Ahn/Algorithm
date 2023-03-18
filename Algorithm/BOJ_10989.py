N = int(input())

count = [0 for _ in range(10001)]

for _ in range(N) :
    x = int(input())
    count[x]+=1
    
for i,n in enumerate(count) :
    for _ in range(n) :
        print(i)