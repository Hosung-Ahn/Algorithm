from collections import Counter

def solution(gems):
    left = 0
    counter = Counter()
    N = len(set(gems))
    ret = []
    
    for right in range(len(gems)) :
        counter[gems[right]] += 1
        while len(counter) == N :
            ret.append([left, right])
            counter[gems[left]] -= 1
            if counter[gems[left]] == 0 :
                del counter[gems[left]]
            left += 1
            
    ret.sort(key=lambda x : (x[1]-x[0], x[0]))
    return [ret[0][0]+1, ret[0][1]+1]