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
        
    cum_sum = [0 for _ in range(play+3)]
    
    
    for i in range(1,len(cum_sum)) :
        cum_sum[i] += cum_sum[i-1] + arr[i-1]
        
    max_dur = 0
    ans = 0
    for t in range(adv, play+1) :
        tmp = cum_sum[t+1]-cum_sum[t-adv]
        if max_dur < tmp :
            ans = t
            max_dur = tmp
            
    return to_string(ans-adv)
