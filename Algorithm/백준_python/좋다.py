import sys
input = sys.stdin.readline

N = int(input())
lst = list(map(int, input().split()))
lst.sort()

def is_good(idx) :
    lo = 0
    hi = N-1
    X = lst[idx]
    while(lo < hi) :
        SUM = lst[lo]+lst[hi]
        if lo == idx or SUM < X : lo += 1
        elif hi == idx or SUM > X : hi -= 1
        else : return True
    return False

ans = 0
for i in range(N) :
    if is_good(i) : 
        ans += 1
print(ans)