#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

int N, V, E;
int A, B;
int home[101];
int dist[1001];
vector<pair<int, int>> graph[1001];
int answer = 0;

void dijkstra(int start) {
	priority_queue<pair<int, int>> pq;

	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int d = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		for (int i = 0; i < (int)graph[node].size(); i++) {
			int next = graph[node][i].first;
			int cost = graph[node][i].second;

			int new_dist = d + cost;

			if (new_dist < dist[next]) {
				dist[next] = new_dist;
				pq.push({ -new_dist, next });
			}
		}
	}
}

int main() {
	cin >> N >> V >> E;
	cin >> A >> B;
	for (int i = 0; i < N; i++)
		cin >> home[i];
	for (int i = 0; i < E; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		graph[from].push_back({ to, cost });
		graph[to].push_back({ from, cost });
	}

	for (int i = 0; i < N; i++) {
		fill(dist, dist + V + 1, INF);
		dijkstra(home[i]);
		if (dist[A] == INF) dist[A] = -1;
		if (dist[B] == INF) dist[B] = -1;
		answer += dist[A] + dist[B];
	}

	cout << answer;

	return 0;
}