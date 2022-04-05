#https://www.acmicpc.net/problem/1753
#1753번-최단 경로
import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n,m = map(int,input().split())
start = int(input())

graph = [[] for _ in range(n+1)]
distance = [INF]*(n+1)

for _ in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))

def dijkstra(start):
    q=[]

    #시작 노드로 가기 위한 최단 경로는 0으로 설정하여, 큐에 삽입
    heapq.heappush(q,(0,start)) #(거리,노드)
    distance[start] = 0

    while q:
        #가장 최단 거리가 짧은 노드에 대한 정보 꺼내기
        dist,now = heapq.heappop(q)

        if distance[now] < dist:
            continue
        
        #d[0]:노드, d[1]:거리
        for d in graph[now]:
            cost = dist + d[1]
            if cost < distance[d[0]]:
                heapq.heappush(q,(cost,d[0]))
                distance[d[0]] = cost

dijkstra(start)

for i in range(1,n+1):
    if distance[i]==INF:
        print("INFINITY")
    else:
        print(distance[i])
