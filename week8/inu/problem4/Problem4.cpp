#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int, int> work;

int N;
int time[10001];
int inEdge[10001];
int endTime[10001];
int ans = 0;
vector<vector<int>> graph;
queue<int> q;

void topological_sort() {
	while (!q.empty()) {
		int qsize = (int)q.size();

		for (int i = 0; i < qsize; i++) {
			int u = q.front(); q.pop();
			int gsize = (int)graph[u].size();

			if (gsize) {
				for (int j = 0; j < (int)graph[u].size(); j++) {
					int v = graph[u][j];
					inEdge[v]--;
					endTime[v] = max(endTime[u] + time[v], endTime[v]);

					if (inEdge[v] == 0)
						q.push(v);
				}
			}
			else
				ans = max(endTime[u], ans);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	graph.assign(N + 1, vector<int>());

	for (int u = 1; u <= N; u++) {
		int n;
		cin >> time[u] >> n;
		inEdge[u] = n;

		for (int i = 0; i < n; i++) {
			int v;
			cin >> v;
			graph[v].push_back(u);
		}
	}

	for (int i = 1; i <= N; i++)
		if (inEdge[i] == 0) {
			q.push(i);
			endTime[i] = time[i];
		}			

	topological_sort();

	cout << ans;

	return 0;
}