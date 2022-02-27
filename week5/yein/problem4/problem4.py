#https://www.acmicpc.net/problem/3055
#3055번-탈출
from collections import deque

n,m = map(int,input().split())
graph = [list(input()) for _ in range(n)]
q = deque()
dx, dy = [-1,1,0,0],[0,0,-1,1]
visited =[[0]*m for _ in range(n)]

for i in range(n):
    for j in range(m):
        if graph[i][j]=='*':
            q.append((i,j))
        elif graph[i][j]=='S':
            q.appendleft((i,j))
        elif graph[i][j]=='D':
            a,b=i,j

def bfs():
    while q:
        x,y = q.popleft()
        for i in range(4):
            nx,ny = x + dx[i],y + dy[i]
            if 0<=nx<n and 0<=ny<m :
                if graph[x][y]=='*':
                    if graph[nx][ny]=='.' or graph[nx][ny]=='S':
                        graph[nx][ny]='*'
                        q.append((nx,ny))
                elif graph[x][y]=='S':
                    if graph[nx][ny]=='.':
                        graph[nx][ny]='S'
                        visited[nx][ny]=visited[x][y]+1
                        q.append((nx,ny))
                    elif graph[nx][ny]=='D':
                        visited[nx][ny]=visited[x][y]+1
                        return visited[nx][ny]
    return visited[a][b]
                        
result = bfs()
print(result if result!=0 else 'KAKTUS' )