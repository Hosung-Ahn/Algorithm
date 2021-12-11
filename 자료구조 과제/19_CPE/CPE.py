import re
from queue import PriorityQueue

n = int(input())
hg_lst = []
for _ in range(n) : 
    text = input()
    text = re.compile("[ㄱ-힣]").findall(text)
    text = list(text)
    hg = [text[i] + text[i+1] for i in range(len(text)-1)]
    hg = set(hg)
    hg_lst.append(hg)
    
pq = PriorityQueue()
for i in range(n) :
    for j in range(i+1, n) : 
        overlap = len(hg_lst[i].intersection(hg_lst[j]))
        pq.put((-overlap, [i+1,j+1]))
        
result = pq.get()[1]
print(result[0], result[1])