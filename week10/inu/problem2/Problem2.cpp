#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;

int d = 0;
int N, V, E;
int kist, food;
vector<int> home;
vector<vector<edge>> graph;
vector<int> dist;

void dijkstra(int start, vector<int>& dist) {
	priority_queue<edge> pq;
	dist[start] = 0;
	pq.push({ 0, start });

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
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N >> V >> E;
	cin >> kist >> food;

	home.assign(N + 1, 0);
	graph.assign(V + 1, vector<edge>());

	for (int i = 0; i < N; i++)
		cin >> home[i];

	for (int i = 0; i < E; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		graph[u].push_back({ v, c });
		graph[v].push_back({ u, c });
	}

	for (int i = 0; i < N; i++) {
		dist.assign(V + 1, INT_MAX);
		dijkstra(home[i], dist);
		d += dist[kist] == INT_MAX ? -1 : dist[kist];
		d += dist[food] == INT_MAX ? -1 : dist[food];
	}

	cout << d;

	return 0;
}