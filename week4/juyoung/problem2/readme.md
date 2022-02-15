# Info

문제 : [트리](https://www.acmicpc.net/problem/4803)

알고리즘 종류 : DFS

참조 url : 


# 1. 알고리즘 설명

사이클을 처리하는 것이 이 문제의 포인트였던 것 같다.

사이클을 처리하기 위해 order 배열을 선언하고, 한 트리 안에서 **각 노드의 방문 순서를 저장**했다.
또한 `visited` 배열 대신 파라미터로 부모 노드 `p`를 넘겼다.


1. 입력을 토대로 연결리스트를 만든다.
2. 1번부터 마지막 정점까지, 이미 방문하지 않은 정점만 깊이 우선 탐색을 한다.
	1. 파라미터로 현재 탐색할 노드와 부모 노드를 넘긴다.
	2. 현재 노드와 연결된 노드들을 탐색한다.
		1. 다음 탐색할 노드가 부모 노드와 같다면 continue 한다.
		2. 다음 탐색할 노드의 방문 순서가 아직 정해지지 않았다면,
			1. 현재 노드의 방문 순서에 1을 더한 수를 저장한다.
			2. dfs를 재귀적으로 호출한다.
		3. 다음 탐색할 노드의 방문 순서가 정해졌다면,
			1. 부모가 아닌데도 현재 노드의 방문 순서보다 다음 노드의 방문 순서가 더 빠르다면 사이클이 존재하는 것이므로 `hasCycle`을 true로 변경한다.
3. `hasCycle`이 true라면 정답을 카운트하지 않고, false라면 정답을 카운트한다.


# 2. 새로 배운 내용(코드 위주)

## 사이클 탐색

### 무방향 그래프

- 다음에 방문할 정점이 부모가 아닌데, 그 정점의 방문 순서가 현재 정점의 방문 순서보다 빠르다면 사이클이 존재하는 것이다.
- `order` 배열에 방문 순서를 저장하고, dfs의 인자로 부모 노드를 넘겨준다.
- ```cpp
	void dfs(int node, int p) {
		for (int i = 0; i < (int)adjList[node].size(); i++) {
			int next = adjList[node][i];
			// 부모라면 뛰어넘기
			if (p == next) continue;
			// 순서가 정해지지 않았다면, 현재 노드의 순서+1 저장
			if (order[next] == 0) {
				order[next] = order[node] + 1;
				dfs(next, node);
			}
			// 부모가 아닌데 방문 순서가 먼저라면 사이클 O
			else if (order[next] < order[node])
				hasCycle = true;
		}
	}
	```


### 방향 그래프

- 다음에 방문할 정점이 이미 방문했지만, 종료되지 않은 정점이라면 사이클이 존재하는 것이다.
- `visited` 배열과 `finihsed` 배열을 활용한다.
- ```cpp
	vector<vector<int>> graph;
	vector<bool> visited, finished;
	bool hasCycle;

	void dfs(int node)
	{
		visited[node] = true;
		for (int i = 0; i < graph[node].size(); i++) {
			int next = graph[node][i];
			if (!visited[next])
				dfs(next);
			// next가 이미 방문했지만, 종료되지 않은 정점이면 사이클 O
			else if (!finished[next])
				hasCycle = true;
		}
		// 해당 정점에 대한 깊이 우선 탐색을 마치면 종료된 정점으로 변경
		finished[node] = true;
	}
	```

- [참고](https://m.blog.naver.com/PostView.nhn?blogId=jh20s&logNo=221248815321&proxyReferer=https:%2F%2Fwww.google.com%2F)
