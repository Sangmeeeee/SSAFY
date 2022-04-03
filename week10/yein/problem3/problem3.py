#https://www.acmicpc.net/problem/1916
#1916번-최소비용 구하기/처음엔 플로이드 와샬로 접근 했으나, 시간 초과남
import heapq
#도시의 개수 
n = int(input())
#버스의 개수
m = int(input())
INF = int(1e9)
graph = [[]*(n+1) for _ in range(n+1)]
distance = [INF]*(n+1)

for _ in range(m):
    a,b,cost = map(int,input().split())
    graph[a].append((b,cost))

start,end = map(int,input().split())

def find (start):
    q = []
    heapq.heappush(q,(0,start))
    distance[start]=0

    while q:
        dist, now = heapq.heappop(q)

        if distance[now]<dist:
            continue

        for i in graph[now]:
            cost = dist + i[1]

            if distance[i[0]] > cost:
                distance[i[0]] = cost
                heapq.heappush(q,(cost,i[0]))

find(start)

print(distance[end])