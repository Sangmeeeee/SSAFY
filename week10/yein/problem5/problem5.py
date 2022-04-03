#https://www.acmicpc.net/problem/1261
#1261번-알고스팟
from collections import deque
m,n = map(int,input().split())
graph = [list(input()) for _ in range(n)]
visited = [[-1]*m for _ in range(n)]
cnt = 0
result = int(1e9)
q = deque([(0,0)])
visited[0][0] = 0
while q:
    x,y = q.popleft()
    for nx,ny in ((x+1,y),(x-1,y),(x,y+1),(x,y-1)):
        if 0<=nx<n and 0<=ny<m and visited[nx][ny]==-1:
            if graph[nx][ny]=='1': #가중치 1 -> append, 0->1 or 1->1
                visited[nx][ny]=visited[x][y]+1
                q.append((nx,ny))
            else: #가중치 0 -> appendleft, 0->0 or 1->0
                visited[nx][ny]=visited[x][y]
                q.appendleft((nx,ny))
print(visited[n-1][m-1])

