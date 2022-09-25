from sys import stdin
from itertools import combinations
input = stdin.readline

def solve(match) :
    if match == 15 : 
        for i in range(6) :
            if sum(res[i]) != 0 : return False
        return True
    t1, t2 = game[match]
    
    for i1,i2 in [[0,2], [1,1], [2,0]] :
        if res[t1][i1] > 0 and res[t2][i2] > 0 : 
            res[t1][i1] -= 1
            res[t2][i2] -= 1
            if solve(match+1) : return 1
            res[t1][i1] += 1
            res[t2][i2] += 1
    return 0
    
game = list(combinations(range(6), 2)) 
ans = []
for _ in range(4) :
    data = list(map(int, input().split()))
    res = [data[i:i+3] for i in range(0,16,3)]
    ans.append(solve(0))

print(*ans)