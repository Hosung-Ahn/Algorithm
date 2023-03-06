from collections import deque

def get_fish():
  ret = []
  for i in range(n):
    for j in range(n):
      if state[i][j] != 0 and state[i][j] < shark:
        ret.append([i, j])
  return ret

def bfs(r, c):
  q = deque()
  q.append((r, c))
  distance[r][c] = 0

  while q:
    row, col = q.popleft()

    for i in range(4):
      if row + dr[i] >= 0 and col + dc[i] >= 0 and row + dr[i] < n and col + dc[i] < n:
        nr = row + dr[i]
        nc = col + dc[i]
        if state[nr][nc] <= shark and distance[nr][nc] == -1:
          q.append((nr, nc))
          distance[nr][nc] = distance[row][col] + 1

dr = [-1, 0, 1, 0]
dc = [0, -1, 0, 1]

n = int(input())

state = []
for _ in range(n):
  state.append(list(map(int, input().split())))

shark = 2
dist = 0
count = 0
position = []

for i in range(n):
  for j in range(n):
    if state[i][j] == 9:
      state[i][j] = 0
      position = [i, j]
      break
  if position != []: break

while True:
  fish = get_fish()
  if fish == []:
    break

  distance = [[-1] * n for _ in range(n)]
  bfs(position[0], position[1])

  for f in fish:
    f.append(distance[f[0]][f[1]])
  fish.sort(key = lambda x : (x[2], x[0], x[1]))

  dist += fish[0][2]
  state[fish[0][0]][fish[0][1]] = 0
  count += 1
  if count == shark:
    shark += 1
    count = 0

  position = [fish[0][0], fish[0][1]]

print(dist)