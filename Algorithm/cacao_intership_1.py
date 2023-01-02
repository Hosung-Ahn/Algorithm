from collections import defaultdict

def solution(survey, choices):
    score = defaultdict(int)
    for i in range(len(survey)) :
        sur = survey[i]
        cho = choices[i]
        if cho > 4 :
            s = cho-4
            score[sur[1]] += s
        elif cho < 4 :
            s = -cho+4
            score[sur[0]] += s
            
    ans = ""
    ans += 'R' if score['R'] >= score['T'] else 'T'
    ans += 'C' if score['C'] >= score['F'] else 'F'
    ans += 'J' if score['J'] >= score['M'] else 'M'
    ans += 'A' if score['A'] >= score['N'] else 'N'
    return ans
    