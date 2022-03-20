# https://www.acmicpc.net/problem/14567
# 14567번-선수과목

from collections import deque
n, m = map(int, input().split())

# 모든 노드에 대한 진입차수는 0으로 초기화
indegree = [0] * (n+1)

# 각 노드에 연결된 간선 정보를 담기 위한 연결 리스트(그래프) 초기화
graph = [[] for i in range(n+1)]

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

# 위상 정렬 함수
def topology_sort():
    # 알고리즘 수행 결과를 담을 리스트
    result = [0]*n
    q = deque()

    # 처음 시작할 때는 진입차수가 0인 노드를 큐에 삽입
    for i in range(1, n+1):
        if indegree[i] == 0:
            q.append((i,1))

    while q:
        # 큐에서 원소 꺼내기
        now,cnt = q.popleft()
        result[now-1] = cnt
        # 해당 원소와 연결된 노드들의 진입차수에서 1 빼기
        for i in graph[now]:
            indegree[i] -= 1
            # 새롭게 진입차수가 0이 되는 노드를 큐에 삽입
            if indegree[i] == 0:
                q.append((i,cnt+1))

    for i in result:
        print(i, end=' ')

topology_sort()
