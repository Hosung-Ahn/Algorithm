N,k = map(int, input().split())

def solve() :
    global k
    i = 0
    while True :
        if k - 9*(10**i)*(i+1) <= 0 :
            break
        k -= 9*(10**i)*(i+1)
        i += 1
    kn = (k-1)//(i+1)
    ki = (k-1)%(i+1)
    n = 10**i + kn
    if n > N : return -1
    return int(str(n)[ki])
    
print(solve())