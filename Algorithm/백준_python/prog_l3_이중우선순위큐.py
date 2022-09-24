import bisect

def solution(operations):
    answer = []
    
    arr = []
    for op in operations : 
        x = int(op[2:])
        if op[0] == 'D' :
           if len(arr) == 0 : continue
           if x == -1 : arr.pop(0)
           else : arr.pop(-1) 
        else :
            bisect.insort(arr, x)
            
    if len(arr) == 0 :
        return [0,0]
    else :
        answer.append(arr[-1])
        answer.append(arr[0])
        return answer
        