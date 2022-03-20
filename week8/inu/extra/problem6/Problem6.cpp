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
	// W�� �ּ� �Ǽ� �ð�
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

		// �Ǽ��� �ɸ��� �ð�
		for (int i = 1; i <= N; i++) {
			cin >> time[i];
		}

		// �Ǽ� ����
		for (int i = 0; i < K; i++) {
			cin >> X >> Y;
			graph[X].push_back(Y);
			indegree[Y]++;
		}

		// ����� �ϴ� �ǹ�
		cin >> W;
		
		// ���� ������ 0�� ��� ã��
		vector<int> start;
		for (int i = 1; i <= N; i++)
			if (indegree[i] == 0)
				start.push_back(i);

		// W ã�� ������ ��������
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