#include <iostream>
#include <vector>
#define INF 2000000000

using namespace std;
typedef pair<int, int> edge;

int N, M;
vector<edge> graph[501];

vector<long long> bellmanFord(int src) {
	vector<long long> upper(N + 1, INF);
	upper[src] = 0;
	bool success;

	// ��� ������ ���� ��ȭ �۾��� N�� �ݺ��Ѵ�.
	for (int iter = 0; iter < N; iter++) {
		success = false;
		for (int u = 1; u <= N; u++) {
			// ���������� ������ �� ���� �����̸� �׳� �ѱ�
			if (upper[u] == INF)
				continue;
			for (int cur = 0; cur < (int)graph[u].size(); cur++) {
				int v = graph[u][cur].first;
				int cost = graph[u][cur].second;				
				// ���� (u, v)�� ���� ��ȭ �õ�
				if (upper[v] > upper[u] + cost) {
					// ��ȭ ����
					upper[v] = upper[u] + cost;
					success = true;
				}
			}
		}
		// ��� ������ ���� ��ȭ�� ���������� �ݺ��� ����
		if (!success) break;
	}
	// ������ N��° ��ȭ �۾��� �����ϸ� ���� ����Ŭ�� �ִ� ��
	if (success) upper.clear();
	return upper;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	int A, B, C;
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		graph[A].push_back({ B, C });
	}

	vector<long long> dist = bellmanFord(1);
	if (dist.empty())
		cout << -1;
	else {
		for (int i = 2; i <= N; i++) {
			if (dist[i] == INF)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}

	return 0;
}