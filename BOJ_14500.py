R,C = map(int, input().split())
board = []
for _ in range(R) :
    board.append(list(map(int, input().split())))
    
ans = 0

for r in range(R) :
    for c in range(C-3) :
        ans = max(ans, sum(board[r][c:c+4]))
        
for r in range(R-3) :
    for c in range(C) :
        tmp = 0 
        for i in range(4) : tmp += board[r+i][c]
        ans = max(ans, tmp)
        
for r in range(R-1) :
    for c in range(C-1) :
        tmp = 0
        for i in range(2) :
            for j in range(2) :
                tmp += board[r+i][c+j]
        ans = max(ans, tmp)
        
arr1 = [[[0,0],[1,0]], [[0,1],[1,1]], [[1,0],[2,0]], [[1,1],[2,1]], [[0,0],[2,0]], [[0,1],[2,1]], [[0,0],[2,1]], [[0,1],[2,0]]]
for r in range(R-2) :
    for c in range(C-1) :
        tmp = 0
        for i in range(3) :
            for j in range(2) :
                tmp += board[r+i][c+j]
        
        for one, two in arr1 :
            ans = max(ans, tmp - board[r+one[0]][c+one[1]] - board[r+two[0]][c+two[1]])
            
            
arr2 = [[[0,0],[0,1]], [[0,1],[0,2]], [[1,0],[1,1]], [[1,1],[1,2]],[[0,0],[0,2]], [[1,0],[1,2]], [[0,0],[1,2]], [[1,0],[0,2]]]
for r in range(R-1) :
    for c in range(C-2) :
        tmp = 0
        for i in range(2) :
            for j in range(3) :
                tmp += board[r+i][c+j]
                
        for one, two in arr2 :
            ans = max(ans, tmp - board[r+one[0]][c+one[1]] - board[r+two[0]][c+two[1]])
            
print(ans)