#https://www.acmicpc.net/problem/4803
#4803번-트리
import sys
input = sys.stdin.readline

def dfs(prev, node):
    visited[node] = True
    for n in graph[node]:
        #graph 배열에서는 연결된 노드를 전체 저장하므로 이전에 방문한 노드를 사이클로 인식할 수 도 있다.
        #이를 방지하기 위해 다음 노드와 이전 노드가 같은지 확인하는 작업을 추가한다.
        if n == prev:
            continue
        #이미 방문한 경우 사이클이 생기므로 트리가 아님
        if visited[n]:
            return False
        if not dfs(node, n):
            return False
    return True

tc = 0
while True:
    tc += 1
    N, M = map(int, input().split())
    if [N, M] == [0, 0]: 
        break
    graph = [[] for _ in range(N+1)] 
    visited = [False] * (N+1)
    for _ in range(M):
        a, b = map(int, input().split())
        graph[a].append(b) 
        graph[b].append(a)

    cnt = 0 # 트리의 개수
    for v in range(1, N+1):
        if not visited[v]:
            if dfs(0, v):
                cnt += 1
    if cnt == 0:
        print("Case {}: No trees.".format(tc))
    elif cnt == 1:
        print("Case {}: There is one tree.".format(tc))
    else:
        print("Case {}: A forest of {} trees.".format(tc, cnt))