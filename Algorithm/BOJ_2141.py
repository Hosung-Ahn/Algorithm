N = int(input())

Sum = 0
arr = []
for _ in range(N) :
    x,a = map(int, input().split())
    Sum += a
    arr.append([x,a])
    
arr.sort()

tmp = 0
for a in arr :
    tmp += a[1]
    if tmp >= Sum/2 :
        print(a[0])
        break