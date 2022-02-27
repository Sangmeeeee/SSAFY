#https://www.acmicpc.net/problem/16197
#16197번-두 동전

#첫째 줄에 두 동전 중 하나만 보드에서 떨어뜨리기 위해 눌러야 하는 버튼의 최소 횟수를 출력한다. 
#만약, 두 동전을 떨어뜨릴 수 없거나, 버튼을 10번보다 많이 눌러야 한다면, -1을 출력한다.

from collections import deque

n,m = map(int,input().split())
board = [list(input()) for _ in range(n)]

dx = [-1,1,0,0]
dy = [0,0,-1,1]

def bfs(x1,y1,x2,y2,cnt):

    q=deque()
    q.append((x1,y1,x2,y2,cnt))

    while q:
        x1,y1,x2,y2,cnt = q.popleft()

        if cnt>=10:
            return -1

        for i in range(4):
            nx1 = x1 + dx[i]
            ny1 = y1 + dy[i]

            nx2 = x2 + dx[i]
            ny2 = y2 + dy[i]

            #coin1과 coin2가 둘다 안떨어 졌으면 큐에 삽입
            if 0<=nx1<n and 0<=ny1<m and 0<=nx2<n and 0<=ny2<m:
                if board[nx1][ny1]=='#':
                    nx1=x1
                    ny1=y1
                if board[nx2][ny2]=='#':
                    nx2=x2
                    ny2=y2

                q.append((nx1,ny1,nx2,ny2,cnt+1))
            #둘다 떨어지거나, 하나만 떨어졌다면
            elif (0<=nx1<n and 0<=ny1<m) or (0<=nx2<n and 0<=ny2<m):
                return cnt+1
    
    return -1

coin= list()
for i in range(n):
    for j in range(m):
        if board[i][j]=='o':
            coin.append(i)
            coin.append(j)

print(bfs(coin[0],coin[1],coin[2],coin[3],0))