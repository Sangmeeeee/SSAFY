#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

int T, N, K;
int time[1001];
int indegree[1001];
int endTime[1001];
vector<vector<int>> graph;

int topological_sort(int W, int start) {
	// W의 최소 건설 시간
	bool flag = false;
	queue<int> q;

	memset(endTime, 0, (N + 1)*sizeof(int));
	endTime[start] = time[start];
	q.push(start);
	
	while (!q.empty()) {
		int u = q.front(); q.pop();

		if (u == W) {
			flag = true;
			break;
		}

		for (int i = 0; i < (int)graph[u].size(); i++) {
			int v = graph[u][i];
			endTime[v] = max(endTime[u] + time[v], endTime[v]);
			indegree[v]--;

			if (indegree[v] == 0)
				q.push(v);
		}
	}

	if (flag)
		return endTime[W];

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int X, Y, W;
	vector<int> ansList;

	cin >> T;

	for (int t = 0; t < T; t++) {		
		cin >> N >> K;

		memset(time, 0, (N + 1) * sizeof(int));
		memset(indegree, 0, (N + 1) * sizeof(int));
		graph.assign(N + 1, vector<int>());

		// 건설에 걸리는 시간
		for (int i = 1; i <= N; i++) {
			cin >> time[i];
		}

		// 건설 순서
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			graph[X].push_back(Y);
			indegree[Y]++;
		}

		// 지어야 하는 건물
		cin >> W;
		
		// 진입 차수가 0인 노드 찾기
		vector<int> start;
		for (int i = 1; i <= N; i++)
			if (indegree[i] == 0)
				start.push_back(i);

		// W 찾을 때까지 위상정렬
		for (int s : start) {
			int ans = topological_sort(W, s);
			if (ans != -1) {
				cout << ans << '\n';
				break;
			}
		}
	}

	return 0;
}