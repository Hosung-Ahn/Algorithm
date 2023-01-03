from collections import deque

def solution(queue1, queue2):
    q1 = deque()
    q2 = deque()
    q1_sum = 0
    q2_sum = 0
    
    for a in queue1 :
        q1.append(a)
        q1_sum += a
    for a in queue2 :
        q2.append(a)
        q2_sum += a
        
    ans = 0
    
    if (q1_sum + q2_sum) % 2 == 1 :
        return -1
    
    while q1_sum != q2_sum :
        if len(q1) == 0 or len(q2) == 0 or ans > len(queue1)*4 : return -1
        print(q1)
        print(q2)
        print()
        ans += 1
        if q1_sum > q2_sum :
            x = q1.popleft()
            q2.append(x)
            q1_sum -= x
            q2_sum += x
        else :
            x = q2.popleft()
            q1.append(x)
            q2_sum -= x
            q1_sum += x
            
    return ans
            
            
print(solution([1, 1, 1, 1, 1, 1, 1, 1, 1, 9], [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]))