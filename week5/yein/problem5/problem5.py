#https://www.acmicpc.net/problem/2206
#2206번-벽 부수고 이동하기
from collections import deque
n,m = map(int,input().split())
graph = [list(map(int,input())) for _ in range(n)]
visited = [[[False]*2 for _ in range(m)] for _ in range(n)]
dx,dy =[0,0,-1,1],[1,-1,0,0] 

q = deque([(0,0,0,1)])
visited[0][0][0] = 1

while q:
    x,y,skill,d = q.popleft()
    if x==n-1 and y==m-1:
        print(d)
        exit()
    for i in range(4):
        nx,ny = dx[i]+x,dy[i]+y
        if 0<=nx<n and 0<=ny<m: 
            if not visited[nx][ny][skill] and graph[nx][ny]==0:
                visited[nx][ny][skill]=True
                q.append((nx,ny,skill,d+1))
            if skill==0 and not visited[nx][ny][1] and graph[nx][ny]==1:
                visited[nx][ny][1]=True
                q.append((nx,ny,skill+1,d+1))
print(-1) 


