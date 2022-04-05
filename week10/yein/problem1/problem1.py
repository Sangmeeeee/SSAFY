#https://programmers.co.kr/learn/courses/30/lessons/12978
#프로그래머스-배달
import heapq

def dijkstra(start,graph,distance):
    q=[]
    heapq.heappush(q,(0,start))
    distance[start]=0

    while q: 
        dist,now = heapq.heappop(q)
        if distance[now] < dist:
            continue
        for i in graph[now]:
            cost=dist+i[1]
            if cost < distance[i[0]]:
                heapq.heappush(q,(cost,i[0]))
                distance[i[0]]=cost
        
def solution(N, road, K):
    answer = 0
    INF = int(1e9)
    distance = [INF]*(N+1)
    graph  = [[] for _ in range(N+1)]
    
    for a,b,cost in road:
        graph[a].append((b,cost))
        graph[b].append((a,cost))
        
    dijkstra(1,graph,distance)
    
    for i in range(1,N+1):
        if distance[i]<=K:
            answer+=1
    
    return answer