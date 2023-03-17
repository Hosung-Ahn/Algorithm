from collections import deque

def bfs():
  q = deque()
  q.append((0, 0, 0))
  graph[0][0] = 1

  while q:
    r, c, b = q.popleft()

    for i in range(4):
      if r + dr[i] < n and c + dc[i] < m and r + dr[i] >= 0 and c + dc[i] >= 0:
        nr = r + dr[i]
        nc = c + dc[i]
        if graph[nr][nc] == 1:
          if nr == 0 and nc == 0: continue

          if b != 0: continue
          else:
            q.append((nr, nc, 1))
            graph[nr][nc] = graph[r][c] + 1

        if graph[nr][nc] == 0:
          if b != 0:
            q.append((nr, nc, 1))
          else:
            q.append((nr, nc, 0))
          graph[nr][nc] = graph[r][c] + 1

        
n, m = map(int, input().split())
graph = []
for _ in range(n):
  lst = list(map(int, list(input())))
  graph.append(lst)

dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

bfs()

result = graph[n - 1][m - 1]
if result == 0:
  print(-1)
else:
  print(result)