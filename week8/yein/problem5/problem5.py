#https://www.acmicpc.net/problem/2252
#2252번-줄 세우기
from collections import deque

n,m = map(int,input().split())
indegree = [0]*(n+1)
graph = [[] for _ in range(n+1)]

for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    indegree[b]+=1

def topology_sort():
    q = deque()
    result = list()

    for i in range(1,n+1):
        if indegree[i]==0:
            q.append(i)
    
    while q:
        now = q.popleft()
        result.append(now)

        for i in graph[now]:
            indegree[i]-=1

            if indegree[i]==0:
                q.append(i)

    print(*result,sep=' ')

topology_sort()
    