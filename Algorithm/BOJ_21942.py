from collections import defaultdict
from sys import stdin
input = stdin.readline

month = [0,0,31,59,90,120,151,181,212,243,273,304,334]

def to_min(day) :
    return (month[day[0]] + day[1])*60*24 + day[2]*60 + day[3]

def diff(day1, day2) :
    return to_min(day1) - to_min(day2)
    

rent = defaultdict(dict)
pays = defaultdict(int)

N,L,F = input().split()
N = int(N)
L = to_min([0] + [int(L.split('/')[0])] + list(map(int, L.split('/')[1].split(':'))))
F = int(F)

for _ in range(N) :
    ym, hm, model, name = input().split()
    day = list(map(int,ym.split('-')[1:])) + list(map(int, hm.split(':')))
    if model in rent[name] :
        pay = max((diff(day, rent[name][model])-L)*F, 0)
        if pay > 0 : pays[name] += pay
        del rent[name][model]
    else :
        rent[name][model] = day

if len(pays.keys()) == 0 : print(-1)
else :
    for name in sorted(pays.keys()) :
        print(name, pays[name])