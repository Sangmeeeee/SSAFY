#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
vector<int> time;
vector<vector<int>> adjList;
vector<int> indegree;
vector<int> dp;
int answer = 0;

void topological_sort() {
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();

		for (int i = 0; i < (int)adjList[node].size(); i++) {
			int next = adjList[node][i];
			dp[next] = max(dp[next], dp[node] + time[next]);
			indegree[next]--;
			if (indegree[next] == 0)
				q.push(next);
		}
	}

	// 선행 관계가 아예 없는 경우 각 작업에 걸리는 시간 중 가장 큰 값이 저장됨
	for (int i = 1; i <= N; i++)
		answer = max(answer, dp[i]);
}

int main() {
	cin >> N;

	time = vector<int>(N + 1, 0);
	dp = vector<int>(N + 1, 0);
	adjList = vector<vector<int>>(N + 1, vector<int>(0, 0));
	indegree = vector<int>(N + 1, 0);

	for (int i = 1; i <= N; i++) {
		cin >> time[i];
		dp[i] = time[i];
		cin >> indegree[i];
		for (int j = 0; j < indegree[i]; j++) {
			int from;
			cin >> from;
			adjList[from].push_back(i);
		}
	}

	topological_sort();
	cout << answer;
	
	return 0;
}