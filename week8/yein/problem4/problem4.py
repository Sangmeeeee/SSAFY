#https://www.acmicpc.net/problem/2056
#2056번-작업
from collections import deque

n = int(input())
indegree = [0]*n
graph = [[] for _ in range(n)]
time = [0]*n
check = [0]*n

for i in range(n):
    a = list(map(int,input().split()))
    time[i] = a[0]
    if a[1]>0:
        a = a[2:]
        for j in range(len(a)):
            graph[a[j]-1].append(i)
            indegree[i]+=1

def topology_sort():
    q = deque()
    ans = 0
    for i in range(n):
        if indegree[i]==0: q.append(i)
    while q:
        now = q.popleft()
        for i in graph[now]:
            indegree[i]-=1
            check[i] = max(check[i],time[now]+time[i])
            if indegree[i]==0:
                time[i]=check[i]
                q.append(i)
    print(max(time))

topology_sort()