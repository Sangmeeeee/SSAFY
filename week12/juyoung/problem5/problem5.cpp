#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define INF 1e9
using namespace std;

int N, A, B, M;
int S, E, P;
vector<tuple<int, int, int>> edge;
long dist[51];
int money[51];
bool cycle;
bool visited[51];

void bfs(int node) {
	queue<int> q;
	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < (int)edge.size(); i++) {
			int from = get<0>(edge[i]);
			int to = get<1>(edge[i]);

			// ���� ���� ������ ��� ������ ����
			// ������ ���� ������ ���� �湮���� ���� ���̶��
			if (curr == from && !visited[to]) {
				visited[to] = true;
				q.push(to);
			}
		}
	}
}

void bellmanford() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (int)edge.size(); j++) {
			int from = get<0>(edge[j]);
			int to = get<1>(edge[j]);
			int cost = get<2>(edge[j]);

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost - money[to]) {
				if (i == N) {
					// ����Ŭ�� ���ԵǴ� ���� ����� ������ visited �迭�� ����
					bfs(from);
					// ���� ���� ��尡 ����Ŭ�� ���ԵǴ� ���� ����Ǿ� �ִٸ�
					// ���� ��忡 �������� �� ���� ������ ���� ���� �� �ְ� ��
					if (visited[B]) {
						cycle = true;
						return;
					}
				}

				dist[to] = dist[from] + cost - money[to];
			}
		}
	}
}

int main() {
	cin >> N >> A >> B >> M;
	for (int i = 0; i < M; i++) {
		cin >> S >> E >> P;
		edge.push_back({ S,E,P });
	}
	for (int i = 0; i < N; i++)
		cin >> money[i];

	// dist �迭�� ���Ѵ�� �ʱ�ȭ, ���� ������ �� �� �ִ� ������ �ʱ�ȭ
	for (int i = 0; i < 51; i++)
		dist[i] = INF;
	dist[A] = -money[A];

	// ��������
	bellmanford();

	if (dist[B] == INF) cout << "gg";
	else if (cycle) cout << "Gee";
	else cout << -dist[B];

	return 0;
}

/*
4 0 3 4
0 1 0
1 2 0
2 1 0
0 3 10
10 10 10 10

��: 10


4 0 3 4
0 1 1
1 2 1
2 0 1
0 3 1
2 2 2 0

��: Gee


3 0 2 4
0 1 9999
1 2 9999
1 1 9999
0 2 0
10000 10000 10000
��: Gee

*/