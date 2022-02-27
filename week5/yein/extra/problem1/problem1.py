#https://www.acmicpc.net/problem/7569
#7569번-토마토

# 상자의 크기를 나타내는 두 정수 M,N과 쌓아올려지는 상자의 수를 나타내는 H
from collections import deque
import sys
input = sys.stdin.readline

m,n,h = map(int,input().split())
arr = [[[0]*h for _ in range(m)] for _ in range(n)]
dx,dy,dz = [1,-1,0,0,0,0],[0,0,1,-1,0,0],[0,0,0,0,1,-1]
q = deque()
check_1 = 0
check_0 = 0

for k in range(h):
    for i in range(n):
        a = list(map(int,input().split()))
        for j in range(m):
            arr[i][j][k] = a[j]
            if(a[j]==1): 
                q.append((i,j,k,0))
                check_1+=1
            elif a[j]==-1: check_0+=1
ans = 0
def bfs():
    global ans,check_1
    while q:
        x,y,z,cnt = q.popleft()
        ans = max(ans,cnt)
        for i in range(6):
            nx = dx[i] + x
            ny = dy[i] + y
            nz = dz[i] + z
            if 0<=nx<n and 0<=ny<m and 0<=nz<h and arr[nx][ny][nz]==0:
                arr[nx][ny][nz] = 1
                q.append((nx,ny,nz,cnt+1))
                check_1+=1
    return  ans

bfs()
if check_1==(n*m*h-check_0): print(ans)
else: print(-1)