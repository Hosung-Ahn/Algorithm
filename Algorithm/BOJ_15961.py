import sys
from collections import defaultdict

input = sys.stdin.readline

arr = []
N,d,k,c = map(int, input().split())
for _ in range(N) :
    x = int(input())
    arr.append(x)
    
dic = defaultdict(int)
for i in range(k) :
    dic[arr[i]] += 1
    
ans = 0
    
for out_idx in range(N) :
    in_idx = (out_idx + (k)) % N
    dic[arr[out_idx]] -= 1
    if dic[arr[out_idx]] == 0 :
        del dic[arr[out_idx]]
    dic[arr[in_idx]] += 1
    
    tmp = len(dic)
    if c not in dic.keys() :
        tmp += 1
    
    ans = max(ans, tmp)
    
print(ans)
    