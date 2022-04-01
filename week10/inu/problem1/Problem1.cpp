#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;

int solution(int N, vector<vector<int>> road, int K) {
	int answer = 0;
	priority_queue<edge> pq;
	vector<vector<edge>> graph(N + 1, vector<edge>());
	vector<int> dist(N + 1, INT_MAX);

	for (int i = 0; i < (int)road.size(); i++) {
		int u = road[i][0], v = road[i][1], c = road[i][2];
		graph[u].push_back({ v, c });
		graph[v].push_back({ u, c });
	}

	dist[1] = 0;
	pq.push({ 0, 1 });

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
				pq.push({ -dist[v], v});
			}
		}
	}

	for (int i = 1; i <= N; i++)
		if (dist[i] <= K)
			answer++;
	
	return answer;
}

int main() {
	vector<vector<int>> road1 = {
		{ 1, 2, 1 },
		{ 2, 3, 3 },
		{ 5, 2, 2 },
		{ 1, 4, 2 },
		{ 5, 3, 1 },
		{ 5, 4, 2 }
	};

	vector<vector<int>> road2 = {
		{ 1,2,1 },
		{ 1,3,2 },
		{ 2,3,2 },
		{ 3,4,3 },
		{ 3,5,2 },
		{ 3,5,3 },
		{ 5,6,1 }
	};

	cout << solution(5, road1, 3) << '\n';
	cout << solution(6, road2, 4);

	return 0;
}