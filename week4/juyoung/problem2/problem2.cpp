#include <iostream>
#include <string.h>
#include <vector>
using namespace std;

vector<vector<int>> adjList;
int order[501];
bool hasCycle;

void dfs(int node, int p) {
	for (int i = 0; i < (int)adjList[node].size(); i++) {
		int next = adjList[node][i];
		if (p == next) continue;
		if (order[next] == 0) {
			order[next] = order[node] + 1;
			dfs(next, node);
		}
		// 부모가 아닌데 방문 순서가 먼저라면 사이클 O
		else if (order[next] < order[node])
			hasCycle = true;
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc = 1;
	while (1) {
		int n, m;
		cin >> n >> m;
		if (n == 0 && m == 0)
			break;

		// 배열 초기화
		adjList.assign(n+1, vector<int>());
		memset(order, false, sizeof(order));

		// 연결리스트 생성
		for (int i = 0; i < m; i++) {
			int n1, n2;
			cin >> n1 >> n2;
			adjList[n1].push_back(n2);
			adjList[n2].push_back(n1);
		}

		int answer = 0;
		for (int i = 1; i <= n; i++)
			if (!order[i]) {
				hasCycle = false;
				dfs(i, i);
				if (hasCycle) continue;
				answer++;
			}

		if (answer > 1)
			cout << "Case " << tc << ": A forest of " << answer << " trees.\n";
		else if (answer == 1)
			cout << "Case " << tc << ": There is one tree.\n";
		else
			cout << "Case " << tc << ": No trees.\n";

		tc++;
	}

	return 0;
}