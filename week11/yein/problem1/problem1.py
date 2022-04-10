#https://www.acmicpc.net/problem/11404
#11404번-플로이드

import sys

INF = int(1e9)
input= sys.stdin.readline

#n:도시의 개수, m:버스의 개수
n=int(input())
m=int(input())

graph=[[INF]*(n+1) for _ in range(n+1)]

#자기 자신으로 가는 노드는 비용 0으로 설정
for a in range(1,n+1):
    for b in range(1,n+1):
        if a==b:
            graph[a][b]=0

for _ in range(m):
    #a: 버스의 시작 도시, b: 도착 도시, c: 한번 타는데 필요한 비용
    a,b,c=map(int,input().split())
    graph[a][b]=min(graph[a][b],c)

#a->b로 가는 최소 비용 구하는 3중 for문
for k in range(1,n+1):
    for a in range(1,n+1):
        for b in range(1,n+1):
            graph[a][b]=min(graph[a][b],graph[a][k]+graph[k][b])

for a in range(1,n+1):
    for b in range(1,n+1):
        if graph[a][b]==INF:
            print('0',end=' ')
        else:
            print(graph[a][b],end=' ')
    #한 줄씩 띄어서 출력
    print()

