from itertools import combinations
import sys

input = sys.stdin.readline

N = int(input())
board = []

for _ in range(N) :
    arr = list(map(int, input().split()))
    board.append(arr)
    
ans = 987654321
for k in range(1,N//2+1) :
    combs = combinations(range(N), k)
    for comb in combs :
        tmp1 = 0
        tmp2 = 0
        team = [False for _ in range(N)]
        for a in comb : team[a] = True
        
        for i in range(N) :
            if team[i] :
                for j in range(i+1,N) :
                    if team[j] :
                        tmp1 += board[i][j] + board[j][i]
        
        for i in range(N) :
            if not team[i] :
                for j in range(i+1,N) :
                    if not team[j] :
                        tmp2 += board[i][j] + board[j][i]
        ans = min(ans, abs(tmp1-tmp2))
        
print(ans)