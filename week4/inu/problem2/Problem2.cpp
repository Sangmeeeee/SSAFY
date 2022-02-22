#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int T = 1;
int N, M;
bool visited[5001];
vector<vector<int>> graph;

bool bfs(int i) {
	int n = 1, e = 0;
	bool result = false;
	queue<int> q;
	q.push(i);
	visited[i] = true;

	while (!q.empty()) {
		int u = q.front();
		q.pop();

		for (int i = 0; i < graph[u].size(); i++) {
			int v = graph[u][i];
			if (!visited[v]) {
				visited[v] = true;
				q.push(v);
				n++;
			}
			e++;
		}
	}

	if (e / 2 == n - 1)
		result = true;
	
	return result;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int T = 1;
	while (1) {
		cin >> N >> M;
		if (N == 0) break;
		graph.assign(N + 1, vector<int>());
		memset(visited, false, N + 1);

		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}

		int cnt = 0;
		for (int i = 1; i <= N; i++)
			if (!visited[i] && bfs(i))
				cnt++;
		
		cout << "Case " << T << ": ";
		if (cnt == 0)
			cout << "No trees." << '\n';
		else if (cnt == 1)
			cout << "There is one tree." << '\n';
		else
			cout << "A forest of " << cnt << " trees." << '\n';

		T++;
	}

	return 0;
}