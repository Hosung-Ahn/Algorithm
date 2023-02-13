def is_ok(r, c, num) :
    for i in range(9) :
        if board[i][c] == num : return False
    for i in range(9) :
        if board[r][i] == num : return False
        
    box_r = r // 3 * 3
    box_c = c // 3 * 3
    
    for i in range(box_r, box_r+3) :
        for j in range(box_c, box_c+3) :
            if board[i][j] == num : return False
            
    return True

def brute(idx) : 
    if idx == 81 : return True
    
    for next_idx in range(idx, 81) :
        r = next_idx // 9
        c = next_idx % 9
        
        if board[r][c] != 0 : continue 
        
        for num in range(1,10) : 
            if is_ok(r,c, num) :
                board[r][c] = num
                if brute(next_idx+1) : return True
                else : board[r][c] = 0

        return False
    return True
    
Input = [input() for _ in range(9)]
board = [[0 for _ in range(9)] for _ in range(9)]

for r in range(9) :
    for c in range(9) :
        board[r][c] = int(Input[r][c])

brute(0)

for s in board :
    print(''.join(map(str, s)))
            

