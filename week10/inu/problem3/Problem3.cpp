#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;

int N, M;
vector<vector<edge>> graph;
vector<int> dist;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	graph.assign(N + 1, vector<edge>());
	dist.assign(N + 1, INT_MAX);

	for (int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v, c });
	}

	int start, end;
	cin >> start >> end;

	priority_queue<edge> pq;
	pq.push({ 0, start });
	dist[start] = 0;
	while (!pq.empty()) {
		int cost = -pq.top().first;
		int u = pq.top().second;
		pq.pop();

		if (dist[u] < cost) continue;

		for (int i = 0; i < (int)graph[u].size(); i++) {
			int v = graph[u][i].first;
			int w = graph[u][i].second;

			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				pq.push({ -dist[v], v });
			}
		}
	}

	cout << dist[end];

	return 0;
}