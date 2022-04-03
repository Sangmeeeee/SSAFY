#https://www.acmicpc.net/problem/12834
#12834번-주간 미팅
import heapq

n,v,e = map(int,input().split())
a,b = map(int,input().split())
h = list(map(int,input().split()))
graph = [[] for _ in range(v+1)]
INF = int(1e9)

for _ in range(e):
    x,y,c = map(int,input().split())
    graph[x].append((y,c))
    graph[y].append((x,c))

def dijkstra(start):
    global a,b,INF
    q = []
    dist = [INF]*(v+1)
    heapq.heappush(q,(0,start))   
    dist[start]=0
    
    while q:
        d, now = heapq.heappop(q)
        if d> dist[now]: continue

        for i in graph[now]:
            cost = i[1] + d
            if cost<dist[i[0]]:
                dist[i[0]] = cost
                heapq.heappush(q,(cost,i[0]))
    
    cnt = 0
    if dist[a]==INF: cnt-=1
    else: cnt+=dist[a]
    if dist[b]==INF: cnt-=1
    else: cnt+=dist[b]

    return cnt

ans = 0
for i in h:
    ans += dijkstra(i)

print(ans)