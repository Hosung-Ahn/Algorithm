import copy

def time_add(time, x) :
    time[1] += x
    time[0] += time[1]//60
    time[1] %= 60
    
def cmp(time1, time2) :
    if time1[0] == time2[0] :
        return time1[1] >= time2[1]
    return time1[0] > time2[0]

def cmp2(time1, time2) :
    if time1[0] == time2[0] :
        return time1[1] < time2[1]
    return time1[0] < time2[0]

def solution(n, t, m, timetable):
    arr = []
    for time in timetable :
        arr.append(list(map(int, time.split(':'))))
        
    arr.sort()
    print(arr)
    
    def f(x) :
        lst = copy.deepcopy(arr)
        start = [9, 0]
        
        for _ in range(n) :
            cnt = 0
            while True :
                if cmp(start, x) and (len(lst)==0 or cmp2(x, lst[0])) :
                    return True
                
                if len(lst) > 0 and cmp(start, lst[0]) :
                    cnt += 1
                    lst.pop(0)
                else : break
                if cnt >= m : break
            print(start, lst)
            time_add(start, t)
            
        print(x, lst)
        return False
    
    times = []
    for H in range(24) :
        for M in range(60) :
            times.append([H,M])
            
    lo = 0
    hi = len(times)-1
    
    while lo < hi :
        mid = (lo+hi)//2+1
        if f(times[mid]) :
            lo = mid
        else : hi = mid-1
        
    H = f"{times[lo][0]:>02}"
    M = f"{times[lo][1]:>02}"
    ans = H+':'+M
    return ans
# print(solution(1,1,5, ["08:00", "08:01", "08:02", "08:03"]))
print(solution(2, 10, 2, ["09:10", "09:09", "08:00"]))

