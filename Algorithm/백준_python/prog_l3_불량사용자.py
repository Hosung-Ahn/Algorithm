
def match(user,ban) :
    if len(user) != len(ban) : return False
    for i in range(len(user)) :
        if ban[i] == '*' : continue
        if user[i] != ban[i] : return False
    return True

def cal_bin(arr) :
    ret = 0
    for i,b in enumerate(arr) :
        ret += 2**i * b
    return ret

def solution(user_id, banned_id):
    
    ans = set()
    visited = [False for _ in range(len(banned_id))]
    selected = [0 for _ in range(len(user_id))]
    
    def dfs(k) :
        nonlocal ans
        if k == len(banned_id) : 
            # print(selected)
            ans.add(cal_bin(selected))
            return
        
        for si, user in enumerate(user_id) :
            for i, ban in enumerate(banned_id) :
                if visited[i] or selected[si] or not match(user, ban) : continue
                selected[si] = 1
                visited[i] = True
                dfs(k+1)
                visited[i] = False
                selected[si] = 0
                
    dfs(0)
    print(ans)
    return(len(ans))
            
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["*rodo", "*rodo", "******"]))
