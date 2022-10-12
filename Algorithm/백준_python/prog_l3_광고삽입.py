def to_num(string) :
    h,m,s = map(int, string.split(':'))
    return h*3600 + m*60 + s

def to_string(num) :
    h = num//3600
    num%=3600
    m = num//60
    num %= 60
    s = num
    return f"{h:>02}:{m:>02}:{s:>02}"


def solution(play_time, adv_time, logs):
    play = to_num(play_time)
    adv = to_num(adv_time)
    arr = [0 for _ in range(play+2)]
    
    for log in logs :
        s,e = map(to_num, log.split('-'))
        arr[s+1] += 1
        arr[e+1] -= 1
        
    for i in range(1,len(arr)) :
        arr[i] += arr[i-1]
        
    # for i,x in enumerate(arr) : 
    #     print(i,x)
        
        
    cum_sum = [0 for _ in range(play+3)]
    
    
    for i in range(1,len(cum_sum)) :
        cum_sum[i] += cum_sum[i-1] + arr[i-1]
    for i,x in enumerate(cum_sum) : 
        print(i,x)
        
    max_dur = 0
    ans = 0
    for t in range(adv, play+1) :
        tmp = cum_sum[t+1]-cum_sum[t-adv]
        if max_dur < tmp :
            ans = t
            max_dur = tmp
            
    return to_string(ans-adv)
    
# print(solution("02:03:55", "00:14:15", ["01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"]))
print(solution("00:01:00", "00:00:10", ['00:00:20-00:00:30',
                                        '00:00:25-00:00:35',
                                        '00:00:30-00:00:40']))
