from collections import deque

n, m = map(int, input().split())
state = [-1] * 100

for _ in range(n + m):
  a, b = map(int, input().split())
  state[a - 1] = b - 1

distance = [0] * 100
visited = [False] * 100

def bfs():
  q = deque()
  q.append(0)
  visited[0] = True

  while q:
    now = q.popleft()

    for i in range(6, 0, -1):
      next = now + i
      if next < 100 and not visited[next]:
        visited[next] = True
        if state[next] != -1 and not visited[state[next]]:
          distance[state[next]] = distance[now] + 1
          visited[state[next]] = True
          q.append(state[next])
          continue

        distance[next] = distance[now] + 1
        q.append(next)
        
bfs()
print(distance[-1])