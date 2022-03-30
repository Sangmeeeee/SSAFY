#include <iostream>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int N, M;
int start, dest;
vector<pair<int, int>> graph[1001];
int dist[1001];

void dijkstra() {
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int d = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		// 이미 최단 경로를 체크한 노드인 경우 패스
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
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		graph[from].push_back({ to, cost });
	}
	cin >> start >> dest;
	fill(dist, dist + N + 1, INF);
	dijkstra();

	cout << dist[dest];
	return 0;
}