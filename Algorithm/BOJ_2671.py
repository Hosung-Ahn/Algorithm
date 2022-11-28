s = input()
i = 0

def f(i) :
    
    try :
        if s[i] == '1' :
            if s[i+1] != '0' or s[i+2] != '0' : return -1
            else : i+=3
            
            while s[i] == '0' : i+=1
            while i < len(s) and s[i] == '1' : i+=1
            return i
        else :
            if s[i+1] != '1' : return -1
            return i+2
    except :
        return -1
    
def solve(i) :
    if i < 0 : return False
    if i == len(s) : return True
    
    nxt = f(i)
    if s[i] == '1' and s[nxt-2] == '1' :
        return solve(nxt) or solve(nxt-1)
    return solve(nxt)

if solve(0) :
    print('SUBMARINE')
else :
    print('NOISE')