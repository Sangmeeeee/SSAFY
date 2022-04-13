#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define INF 1e9
using namespace std;

int n, m;
int u, v, w;
vector<tuple<int, int, int>> road;	// �Է� ���� ���� ���� ����
int dist[101];		// �ִ� �Ÿ� ����
int parent[101];	// ������ �湮�� ��� ����
bool visited[101];	// �������� ����� ������ ǥ��
bool cycle;			// ���������� ���� �� ���� ����Ŭ�� ����
vector<int> path;	// parent �迭�� ����� ������ ���� ��θ� ����

void bfs(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < (int)road.size(); i++) {
			int start = get<0>(road[i]);
			int end = get<1>(road[i]);

			// ���� ����Ʈ ���°� �ƴ϶� ���� ���θ� road ���Ϳ� ���������Ƿ�
			// ť���� ���� ���� for������ �����ϰ� �ִ� ������ ��� ��尡 ������
			// �˻��ϴ� ������ �ʿ��ϴ�.
			// ���� ���� ������ ���� ��带 �湮���� �ʾ��� ������
			// visited �迭�� �����ϰ� ť�� ���� ������ ���� ��带 �����Ѵ�.
			if (curr == start && !visited[end]) {
				visited[end] = true;
				q.push(end);
			}
		}
	}
}

void bellmanford() {
	// n-1�� ���� �� �� �� ������ ���� ����Ŭ ���� �˻�
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)road.size(); j++) {
			int from = get<0>(road[j]);
			int to = get<1>(road[j]);
			int cost = get<2>(road[j]);

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) {
				// n��° ������ ��, �� i=n�� �� �� ��ȭ�� �ְ�
				// �������� ����� �����(=bfs ���� visited[n]�� true���)
				// �������� ���� ��ο� ���� ����Ŭ�� �����ϴ� ���̴�.
				if (i == n) {
					// from�� ����� ������ visited �迭�� ǥ��
					bfs(from);
					if (visited[n]) {
						cycle = true;
						return;
					}
				}

				dist[to] = dist[from] + cost;
				parent[to] = from; // �θ� ��� ����
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		road.push_back({ u,v,-w });
	}

	// ��������� �ִ� �Ÿ� �� ���� ����Ŭ ���� ���ϱ�
	for (int i = 2; i <= n; i++) dist[i] = INF;
	bellmanford();

	// 1. ��������� �������� ���� ��ΰ� �ƿ� ���ų�
	// 2. �������� ���� ��ο� ���� ����Ŭ�� �����ϸ� ����
	if (dist[n] == INF || cycle)
		cout << -1;
	// 3. ����Ŭ�� �������� ������ ��� ���
	else if (!cycle) {
		int node = n;
		path.push_back(node);
		// �����ص� �θ� ��带 �Ž��� �ö󰡸� ��� ����
		while (parent[node] > 0) {
			path.push_back(parent[node]);
			node = parent[node];
		}

		for (int i = (int)path.size() - 1; i >= 0; i--)
			cout << path[i] << " ";
	}

	return 0;
}

/*
5 7
1 2 3
1 3 4
3 1 -7
2 3 2
3 4 1
4 2 -5
4 5 1

��: 1 2 3 4 5


5 7
1 2 3
1 3 4
3 1 -7
2 3 2
3 4 1
4 2 -2
4 5 1

��: -1


5 7
1 2 1
2 3 1
3 4 1
4 5 1
1 5 10
1 2 50
2 5 80

��: 1 2 5


5 5
1 2 -1
2 3 1
3 4 1
4 2 1
2 5 -1

��: -1


4 4
1 4 3
2 3 1
3 2 1
4 2 1

�� : 1 4


4 4
1 2 1
2 3 1
3 4 1
4 1 1

�� : -1


4 5
1 2 1
2 3 1
3 4 1
3 2 1
4 1 1

�� : -1


4 5
1 2 1
2 3 1
3 4 1
3 1 1
4 1 1

�� : -1
*/