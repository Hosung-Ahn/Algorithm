def solution(operations):
    answer = []
    
    for op in operations : 
        if op[0] == 'D' :
            print('D :', int(op[2:]))
        else :
            print('I :', int(op[2:]))
            
solution(["I 16", "I -5643", "D -1", "D 1", "D 1", "I 123", "D -1"])