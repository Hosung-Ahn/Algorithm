def reverse(lst, i,j) :
    lst_copy = lst[:]
    lst_copy[i:j] = lst_copy[i:j][::-1]
    return lst_copy

def bfs(perm) :
    end = sorted(perm)
    distance = dict()
    distance[' '.join(list(map(str, perm)))] = 0
    q = [perm]
    
    while q :
        cur = q[0]
        q.pop(0)
        
        cur_s = ' '.join(list(map(str, cur)))
        if cur == end : return distance[cur_s]
        
        for i in range(len(perm)) :
            for j in range(i+2, len(perm)+1) :
                reversed = reverse(cur, i,j)
                reversed_s = ' '.join(list(map(str, reversed)))
                if reversed_s in distance.keys() : continue
                distance[reversed_s] = distance[cur_s] + 1
                q.append(reversed)
                
    return 0

T = int(input())
while T :
    T -= 1
    a = int(input())
    arr = list(map(int, input().split()))
    print(bfs(arr))                
    