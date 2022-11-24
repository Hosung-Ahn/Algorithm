MAX = 10_000_000
prime = [True for _ in range(MAX+1)]
check = int(MAX**0.5)

arr = []

for i in range(2, check+1) :
    if prime[i] :
        for j in range(i*2, MAX+1, i) :
            prime[j] = False
            
def push(p, arr) :
    x = p*p
    while(x <= MAX**2) :
        arr.append(x)
        x *= p
        
def lower(arr, x) :
    lo = 0
    hi = len(arr)-1
    while lo < hi :
        mid = (lo+hi)//2
        if arr[mid] < x : lo = mid+1
        else : hi = mid
    return lo

def upper(arr, x) :
    lo = 0
    hi = len(arr)-1
    while lo < hi :
        mid = (lo+hi)//2+1
        if arr[mid] <= x : lo = mid
        else : hi = mid-1
    return lo

for i in range(2, MAX+1) :
    if prime[i] :
        push(i, arr)
arr.sort()

a,b = map(int, input().split())

ai = lower(arr, a)
bi = upper(arr, b)

print(bi-ai+1)