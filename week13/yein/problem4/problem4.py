#https://www.acmicpc.net/problem/1976
#1976번-여행 가자

#도시의 수
n = int(input())
#여행 계획에 속한 도시들의 수
m = int(input())

INF = int(1e9)
graph = [list(map(int,input().split())) for _ in range(n)]
travel = list(map(int,input().split()))

for i in range(n):
    for j in range(n):
        if graph[i][j]==0 and i!=j:
            graph[i][j]=INF

for k in range(n):
    for a in range(n):
        for b in range(n):
            graph[a][b] = min(graph[a][b],graph[a][k]+graph[k][b])
check = True
for i in range(len(travel)-1):
    if graph[travel[i]-1][travel[i+1]-1]==0:
        check = False
        break
if check:
    print('YES')
else:
    print('NO')
