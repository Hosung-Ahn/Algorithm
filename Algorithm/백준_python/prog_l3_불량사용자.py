
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
    ans = 0
    ban_visited = [False for _ in range(len(banned_id))]
    selected = [0 for _ in range(len(user_id))]
    visited = [False for _ in range(1000)]
    
    def dfs(k) :
        nonlocal ans
        cach = cal_bin(selected)
        
        if visited[cach] : return
        visited[cach] = True
        
        if k == len(banned_id) : 
            ans += 1
            return
        
        for si, user in enumerate(user_id) :
            for i, ban in enumerate(banned_id) :
                if ban_visited[i] or selected[si] or not match(user, ban) : continue
                selected[si] = 1
                ban_visited[i] = True
                dfs(k+1)
                ban_visited[i] = False
                selected[si] = 0
                
    dfs(0)
    return(ans)
            
print(solution(["frodo", "fradi", "crodo", "abc123", "frodoc"], ["*rodo", "*rodo", "******"]))
