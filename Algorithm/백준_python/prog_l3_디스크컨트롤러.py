from queue import PriorityQueue

def f(x) :
    return x[1]

def solution(jobs):
    jobs.sort()
    pq = PriorityQueue()
    ans = 0
    time = 0
    used = 0
    selected = [False for _ in range(len(jobs))]
    while used < len(jobs) :
        for i, job in enumerate(jobs) :
            if selected[i] : continue
            if job[0] <= time :
                pq.put((f(job), job))
                selected[i] = True
                
        if pq.empty() :
            time += 1
            
        else :
            a = pq.get()[1]
            time += a[1]
            ans += time - a[0]
            used += 1
    
    return ans//len(jobs)
            
print(solution([[0, 3], [1, 9], [2, 6]]))
