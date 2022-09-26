arr = [ [0 for _ in range(10)] for _ in range(10)]

def f() :
    arr[0][0] = 10
    
f()

for a in arr :
    print(a)