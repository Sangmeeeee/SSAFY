# Info

���� : [Ʈ��](https://www.acmicpc.net/problem/4803)

�˰��� ���� : DFS

���� url : 


# 1. �˰��� ����

����Ŭ�� ó���ϴ� ���� �� ������ ����Ʈ���� �� ����.

����Ŭ�� ó���ϱ� ���� order �迭�� �����ϰ�, �� Ʈ�� �ȿ��� **�� ����� �湮 ������ ����**�ߴ�.
���� visited �迭 ��� �Ķ���ͷ� �θ� ���(p)�� �Ѱ��.


1. �Է��� ���� ���Ḯ��Ʈ�� �����.
2. 1������ ������ ��������, �̹� �湮���� ���� ������ ���� �켱 Ž���� �Ѵ�.
	1. �Ķ���ͷ� ���� Ž���� ���� �θ� ��带 �ѱ��.
	2. ���� ���� ����� ������ Ž���Ѵ�.
		1. ���� Ž���� ��尡 �θ� ���� ���ٸ� continue �Ѵ�.
		2. ���� Ž���� ����� �湮 ������ ���� �������� �ʾҴٸ�,
			1. ���� ����� �湮 ������ 1�� ���� ���� �����Ѵ�.
			2. dfs�� ��������� ȣ���Ѵ�.
		3. ���� Ž���� ����� �湮 ������ �������ٸ�,
			1. �θ� �ƴѵ��� ���� ����� �湮 �������� ���� ����� �湮 ������ �� �����ٸ� ����Ŭ�� �����ϴ� ���̹Ƿ� `hasCycle`�� true�� �����Ѵ�.
3. `hasCycle`�� true��� ������ ī��Ʈ���� �ʰ�, false��� ������ ī��Ʈ�Ѵ�.


# 2. ���� ��� ����(�ڵ� ����)

### ����Ŭ Ž��

1. ������ �׷���

- ������ �湮�� ������ �θ� �ƴѵ�, �� ������ �湮 ������ ���� ������ �湮 �������� �����ٸ� ����Ŭ�� �����ϴ� ���̴�.
- `order` �迭�� �湮 ������ �����ϰ�, dfs�� ���ڷ� �θ� ��带 �Ѱ��ش�.
- ```cpp
	void dfs(int node, int p) {
		for (int i = 0; i < (int)adjList[node].size(); i++) {
			int next = adjList[node][i];
			// �θ��� �پ�ѱ�
			if (p == next) continue;
			// ������ �������� �ʾҴٸ�, ���� ����� ����+1 ����
			if (order[next] == 0) {
				order[next] = order[node] + 1;
				dfs(next, node);
			}
			// �θ� �ƴѵ� �湮 ������ ������� ����Ŭ O
			else if (order[next] < order[node])
				hasCycle = true;
		}
	}
	```

2. ���� �׷���

- ������ �湮�� ������ �̹� �湮������, ������� ���� �����̶�� ����Ŭ�� �����ϴ� ���̴�.
- `visited` �迭�� `finihsed` �迭�� Ȱ���Ѵ�.
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
			// next�� �̹� �湮������, ������� ���� �����̸� ����Ŭ O
			else if (!finished[next])
				hasCycle = true;
		}
		// �ش� ������ ���� ���� �켱 Ž���� ��ġ�� ����� �������� ����
		finished[node] = true;
	}
	```

- [����](https://m.blog.naver.com/PostView.nhn?blogId=jh20s&logNo=221248815321&proxyReferer=https:%2F%2Fwww.google.com%2F)
