#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M;
int A, B, C;
int S, E;
vector<int> root;
vector<tuple<int, int, int>> edge;
vector<vector<pair<int, int>>> adjList;
vector<bool> visited;
vector<int> dist;
int answer = 1e9*2;

int find(int x) {
	if (x == root[x])
		return x;
	return root[x] = find(root[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	// �� ���� ���� �������� �θ� ��带 �����Ѵ�.
	if (x < y) root[y] = x;
	else root[x] = y;
}

bool dfs(int node, int depth) {
	// ���� ������ ��ġ�� �ٸ� ���� �����ߴٸ�
	if (node == E) {
		// �߷� ���� �� �ּڰ��� ã�´�.
		for (int i = 0; i < depth; i++)
			answer = min(answer, dist[i]);
		return true;
	}

	// ��������Ʈ�� Ž���Ѵ�.
	for (int i = 0; i < (int)adjList[node].size(); i++) {
		int next = adjList[node][i].first;
		int cost = adjList[node][i].second;
		
		if (visited[next]) continue;
		visited[next] = true;
		dist[depth] = cost;
		// ���� �������� �����Ͽ� ������ ã�Ҵٸ� ���������� true�� �����Ѵ�.
		if (dfs(next, depth + 1)) return true;
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i <= N; i++) root.push_back(i);
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		// �������� ������ ���� �߷� ������ ������ �����Ѵ�.
		edge.push_back({ -C,A,B });
	}
	cin >> S >> E;

	// 1. Kruskal �˰��� ����
	// Kruskal �˰����� �����Ͽ� ����� ������ ���� ���δ�.
	sort(edge.begin(), edge.end());

	adjList.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int c = -get<0>(edge[i]);
		int a = get<1>(edge[i]);
		int b = get<2>(edge[i]);

		// �� ���� �������� �� ����Ŭ�� ����ٸ� �н��Ѵ�.
		if (find(a) == find(b)) continue;
		Union(a, b);
		// DFS�� ���� ��������Ʈ�� �����Ѵ�.
		adjList[a].push_back({ b, c });
		adjList[b].push_back({ a, c });
	}

	// 2. DFS ����
	for (int i = 0; i <= N; i++) {
		visited.push_back(false);
		dist.push_back(-1);
	}
	visited[S] = true;
	dfs(S, 0);

	// ���� ������ ��ġ�� �� ���� ���� ������ �� ���ٸ� 0�� ����ϰ�
	// �׷��� �ʴٸ� answer�� ����Ѵ�.
	if (answer == 1e9*2) cout << 0;
	else cout << answer;

	return 0;
}

/*
10000 3
9998 9999 2
10000 9998 3
9999 10000 2
9998 10000

����: 3


5 5
1 2 5
2 3 4
1 3 3
1 4 3
4 5 1
5 1

����: 1


6 9
1 2 7
1 3 8
1 4 7
1 6 9
2 3 7
3 4 7
3 5 7
4 5 7
4 6 7
6 3

����: 8


6 12
1 2 7
1 3 8
1 4 7
1 6 9
2 3 7
3 4 7
3 5 7
4 5 7
4 6 7
3 6 7
1 3 11
5 6 12
6 3

����: 9


3 1
1 2 999999999
1 2

����: 999999999

3 3
1 2 2
3 1 2
2 3 2
1 3

����: 2

3 3
1 2 2
3 1 2
2 3 99999999
1 3

����:2


9 9
1 4 11
1 5 2
4 5 4
4 3 10
4 2 7
5 2 10
5 6 13
3 2 9
2 6 8
1 6

����: 9
*/