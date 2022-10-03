def solution(enroll, referral, seller, amount):
    hashing = dict()
    for i, name in enumerate(enroll) :
        hashing[name] = i
    
    result = [0 for _ in range(len(enroll))]
    
    for s,a in zip(seller, amount) :
        m = a*100
        while s != '-' or m > 0 :
            result[hashing[s]] += m - m//10
            m //= 10
            s = referral[hashing[s]]
            
    return result