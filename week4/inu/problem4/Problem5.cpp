#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> graph;
vector<bool> visited;

/*
5 5
0 1
1 3
1 2
2 3
3 4
*/

int dfs(int u, int cnt) {
	visited[u] = true;

	if (cnt == 5)
		return 1;

	for (int i = 0; i < graph[u].size(); i++) {
		int v = graph[u][i];
		if (!visited[v]) {
			if (dfs(v, cnt + 1))
				return 1;
			visited[v] = false;
		}	
	}

	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	graph.assign(N, vector<int>());
	visited.assign(N, false);

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	cout << dfs(0, 1);

	return 0;
}