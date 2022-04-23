#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

vector<vector<pair<int, int>>> graph;
int max_weight = 0;

bool bfs(int s, int e, int v) {
	queue<int> q;
	bool visited[10001];
	memset(visited, false, sizeof(bool) * 10001);

	q.push(s);
	visited[s] = true;
	
	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == e)
			return true;

		for (auto p : graph[cur]) {
			if (p.second >= v && !visited[p.first]) {
				visited[p.first] = true;
				q.push(p.first);
			}
				
		}
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int a, b, c;

	cin >> N >> M;
	
	graph.resize(N + 1);
	
	for (int i = 0; i < M; i++) {
		cin >> a >> b >> c;

		graph[a].push_back({ b, c });
		graph[b].push_back({ a, c });

		max_weight = max(max_weight, c);
	}

	cin >> a >> b;

	int left = 0, right = max_weight;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		// 목적지까지 옮길 수 있을 때
		if (bfs(a, b, mid) == true)
			left = mid + 1;
		// 목적지까지 옮길 수 없을 때
		else
			right = mid - 1;
	}

	cout << right;

	return 0;
}