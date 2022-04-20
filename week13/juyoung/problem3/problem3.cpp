#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M;
int s, e;
vector<tuple<int, int, int>> edge;
vector<int> root;
vector<vector<pair<int, int>>> adjList;
vector<bool> visited;
vector<int> dist;
int answer = 1e9;

int find(int x) {
	if (root[x] == x)
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

bool dfs(int node, int cnt) {
	// ���� ������ �����ϸ�
	if (node == e) {
		// s���� e�� ���� ��� ���� ���� �� ���� ������ �ּڰ��� ã�´�.
		for (int i = 0; i < cnt; i++)
			answer = min(answer, dist[i]);
		return true;
	}

	for (int i = 0; i < (int)adjList[node].size(); i++) {
		int next = adjList[node][i].first;
		int cost = adjList[node][i].second;

		if (visited[next]) continue;
		visited[next] = true;
		dist[cnt] = cost;
		// ���� ���������� �����ߴٸ� ���������� true�� return �Ѵ�.
		if (dfs(next, cnt + 1)) return true;
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	cin >> s >> e;

	// ��Ʈ ��带 �ʱ�ȭ�Ѵ�.
	for (int i = 0; i <= N; i++) root.push_back(i);

	for (int i = 0; i < M; i++) {
		int h1, h2, k;
		cin >> h1 >> h2 >> k;
		// �ִ밪�� ���ؾ��ϹǷ� ����� ������ �Է� �޴´�.
		edge.push_back({ -k, h1, h2 });
	}

	// 1. Kruskal �˰��� ����
	// ������ �����Ѵ�.
	sort(edge.begin(), edge.end());

	// ������ �����Ѵ�.
	adjList.resize(N + 1);
	for (int i = 0; i < edge.size(); i++) {
		int k = -get<0>(edge[i]); // ���� ����
		int x = get<1>(edge[i]); // ��� ����
		int y = get<2>(edge[i]); // ���� ����

		// x�� y�� �������� �� ����Ŭ�� ����ٸ� �������� �ʰ� �н��Ѵ�.
		if (find(x) == find(y)) continue;
		// ����Ŭ�� ������ �ʴ´ٸ� �����Ѵ�.
		Union(x, y);
		// DFS�� ���� ���ο� ��������Ʈ�� �����Ѵ�.
		adjList[x].push_back({ y, k });
		adjList[y].push_back({ x, k });
	}

	// 2. DFS ����
	for (int i = 0; i <= N; i++) {
		visited.push_back(false);
		dist.push_back(-1);
	}
	visited[s] = true;
	dfs(s, 0);

	// s���� e���� �� �� ���ٸ� 0 ���
	// �ƴ϶�� ���� ���
	if (answer == 1e9) cout << 0;
	else cout << answer;

	return 0;
}