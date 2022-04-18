#https://www.acmicpc.net/problem/1865
#1865번-웜홀
INF = int(1e9)

def bf(n):
    for i in range(1,n+1):
        for j in range(1,n+1):
            for node,cost in graph[j]:
                if dist[node] > dist[j] + cost: 
                    dist[node] = dist[j] + cost
                    if i == n: return True
    return False
                

for _ in range(int(input())):
    n,m,w = map(int,input().split())
    graph = [[] for _ in range(n+1)]
    dist = [INF]*(n+1)

    for _ in range(m):
        s,e,t = map(int,input().split())
        graph[s].append((e,t))
        graph[e].append((s,t))

    for _ in range(w):
        s,e,t = map(int,input().split())
        graph[s].append((e,-t))

    print("YES" if bf(n) else "NO" )