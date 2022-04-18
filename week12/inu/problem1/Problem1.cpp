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

	// 모든 간선에 대한 완화 작업을 N번 반복한다.
	for (int iter = 0; iter < N; iter++) {
		success = false;
		for (int u = 1; u <= N; u++) {
			// 시작점에서 도달할 수 없는 정점이면 그냥 넘김
			if (upper[u] == INF)
				continue;
			for (int cur = 0; cur < (int)graph[u].size(); cur++) {
				int v = graph[u][cur].first;
				int cost = graph[u][cur].second;				
				// 간선 (u, v)에 대한 완화 시도
				if (upper[v] > upper[u] + cost) {
					// 완화 성공
					upper[v] = upper[u] + cost;
					success = true;
				}
			}
		}
		// 모든 간선에 대해 완화가 실패했으면 반복문 종료
		if (!success) break;
	}
	// 마지막 N번째 완화 작업도 성공하면 음수 사이클이 있는 것
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