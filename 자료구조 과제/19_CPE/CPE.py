#-*- encoding: utf-8 -*-
import re
from queue import PriorityQueue
import sys
with open(sys.stdin.fileno(), encoding='utf8') as std_input:
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
            total = len(hg_lst[i].union(hg_lst[j]))
            try : 
                sim = overlap / total
            except : 
                sim = 0
            pq.put((-sim, [i+1,j+1]))

    print(*pq.get()[1])