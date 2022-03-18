#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int indegree[32001];
bool visited[32001];
vector<vector<int>> graph;

void topological_sort(queue<int> q) {
	while (!q.empty()) {
		int u = q.front(); q.pop();
		cout << u << ' ';
		
		for (int i = 0; i < (int)graph[u].size(); i++) {
			int v = graph[u][i];
			indegree[v]--;
			if (indegree[v] == 0)
				q.push(v);	
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	graph.assign(N + 1, vector<int>());
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		graph[u].push_back(v);
		indegree[v]++;
	}

	vector<int> front;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			front.push_back(i);

	for (int i : front) {
		queue<int> q;
		q.push(i);
		topological_sort(q);
	}

	return 0;
}