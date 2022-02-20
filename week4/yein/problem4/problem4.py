#https://www.acmicpc.net/problem/13023
#13023번-ABCDE

n,m = map(int,input().split())
graph = [[] for _ in range(n)]
visited = [False]*n
for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

def dfs(now,cnt):
    global check
    visited[now]=True
    if cnt==4:
        check=True
        return 
    for i in graph[now]:
        if not visited[i]:
            dfs(i,cnt+1)
            visited[i]=False
check = False
for i in range(n):
    dfs(i,0)
    visited[i]=False
    if check:break
print(0 if not check else 1)