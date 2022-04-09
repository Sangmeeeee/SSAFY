#include <iostream>
#include <queue>
#include <vector>
#define INF 1e9
using namespace std;

int V, E;
int K;
vector<pair<int, int>> graph[20001];
int dist[20001];

void dijkstra() {
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, K });
	dist[K] = 0;

	while (!pq.empty()) {
		int d = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		if (dist[node] < d)
			continue;

		for (int i = 0; i < (int)graph[node].size(); i++) {
			int next = graph[node][i].first;
			int cost = graph[node][i].second;
			int new_cost = d + cost;

			if (new_cost < dist[next]) {
				dist[next] = new_cost;
				pq.push({ -new_cost, next });
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> V >> E;
	cin >> K;
	for (int i = 0; i < E; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}

	fill(dist, dist + V + 1, INF);
	dijkstra();

	for (int i = 1; i <= V; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}