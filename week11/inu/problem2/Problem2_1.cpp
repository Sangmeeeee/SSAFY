#include <iostream>
#include <vector>
#include <queue>
#define INF 10000

using namespace std;

typedef pair<int, int> edge;

int N, M, R;
int max_items = 0;
int dist[101][101];
vector<vector<edge>> graph;
vector<int> items;

int dijkstra(int i) {
	int result = 0;
	priority_queue<edge> pq;
	
	pq.push({ 0, i });
	dist[i][i] = 0;
	while (!pq.empty()) {
		int l = -pq.top().first;
		int u = pq.top().second;	
		pq.pop();

		for (int j = 0; j < (int)graph[u].size(); j++) {
			int v = graph[u][j].first;
			int w = graph[u][j].second;
			if (dist[i][u] + w < dist[i][v]) {
				dist[i][v] = dist[i][u] + w;
				pq.push({ -dist[i][v], v });
			}
		}
	}

	for (int j = 1; j <= N; j++)
		if (dist[i][j] <= M)
			result += items[j];

	return result; 
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> R;

	graph.resize(N + 1);
	items.assign(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> items[i];

	for (int i = 0; i < R; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		graph[a].push_back({ b, l });
		graph[b].push_back({ a, l });
	}

	for (int j = 1; j <= N; j++)
		for (int k = 1; k <= N; k++)
			dist[j][k] = INF;

	for (int i = 1; i <= N; i++) {
		int result = dijkstra(i);
		max_items = result > max_items ? result : max_items;
	}

	cout << max_items;

	return 0;
}