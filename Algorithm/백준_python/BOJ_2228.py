import sys
input = sys.stdin.readline


arr = []
N,K = map(int, input().split())
M = N-K+1

for _ in range(N) :
    x = int(input())
    arr.append(x)

ans = -987654321

Sum = [0 for _ in range(N)]
for i in range(N) :
    if i >= M : break
    for j in range(i,N) :
        Sum[j-i] += arr[j]
        if K==2 and i-j != 0 and j!=N-1:
            continue
        ans = max(ans, Sum[j-i])
        
print(ans)