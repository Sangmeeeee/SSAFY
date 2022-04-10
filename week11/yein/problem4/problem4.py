#https://www.acmicpc.net/problem/21278
#21278번-호석이 두 마리 치킨

#첫번째 풀이(플로이드-워셜 + 조합)
from itertools import combinations
INF = int(1e9)
n,m = map(int,input().split())
graph = [[INF]*(n+1) for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    graph[a][b]=1
    graph[b][a]=1
for i in range(1,n+1):
    graph[i][i]=0

for k in range(1,n+1):
    for a in range(1,n+1):
        for b in range(1,n+1):
            graph[a][b]= min(graph[a][b],graph[a][k]+graph[k][b])
result = []
for a,b in combinations(range(1,n+1),2):
    cnt = 0
    for i in range(1,n+1):
        for j in (a,b):
            cnt+=min(graph[i][a],graph[i][b])
    result.append((a,b,cnt))
print(*sorted(result,key = lambda x:(x[2],x[0],x[1]))[0],sep=' ')


#두번째 풀이 (bfs + 조합)
from collections import deque
from itertools import combinations
n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
result = []
def calc(chicken):
    result = 0
    dist = [-1]*(n+1)
    q = deque()
    for c in chicken:
        q.append(c)
        dist[c]=0
    while q:
        now = q.popleft()
        for i in graph[now]:
            if dist[i]==-1:
                dist[i]=dist[now]+1
                q.append(i)
    return sum(dist[1:])*2

for a,b in combinations(range(1,n+1),2):
    result.append((a,b,calc([a,b])))
print(*sorted(result,key = lambda x:(x[2],x[0],x[1]))[0],sep=' ')