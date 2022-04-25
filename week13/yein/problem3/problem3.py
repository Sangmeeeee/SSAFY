#https://www.acmicpc.net/problem/13905
#13905번-세부
import heapq
import sys
input = sys.stdin.readline
INF = int(1e9)

n, m = map(int,input().split())
s, e = map(int,input().split())
distance = [0]*(n+1)
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a,b,c = map(int,input().split())
    graph[a].append((b,c))
    graph[b].append((a,c))

def dijkstra(start,end):
    q = []
    heapq.heappush(q,(-INF,start))
    distance[start] = 0
    while q:
        d,now = heapq.heappop(q)
        d = -d
        if distance[now]>d: continue

        for i in graph[now]:
            min_cost = min(d,i[1])
            if min_cost>distance[i[0]]:
                distance[i[0]] = min_cost
                heapq.heappush(q,(-min_cost,i[0]))

    return distance[end]

print(dijkstra(s,e))