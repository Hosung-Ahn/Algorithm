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
        print(1, end='')
        if len(q1) == 0 or len(q2) == 0 or ans > (len(queue1)+len(queue2)) : return -1
        
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
            
            
print(solution([4,5], [6,11]))