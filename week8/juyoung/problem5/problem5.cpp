#include <iostream>
#include <vector>
#include <queue>
#define MAX 32001
using namespace std;

int N, M;
int indegree[MAX];
vector<int> adjList[MAX];

void topological_sort() {
	queue<int> q;

	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) 
			q.push(i);
	}

	while (!q.empty()) {
		int node = q.front();
		q.pop();
		cout << node << " ";

		for (int i = 0; i < (int)adjList[node].size(); i++) {
			int next = adjList[node][i];
			indegree[next]--;
			if (indegree[next] == 0) 
				q.push(next);
		}
	}
}

int main() {
	// 입력 및 인접리스트 생성
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		indegree[to]++;
		adjList[from].push_back(to);
	}

	topological_sort();

	return 0;
}