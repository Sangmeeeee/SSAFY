#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> adjList;	// 인접리스트
vector<int> degree;				// 진입 차수
vector<int> semester;			// 학기 저장

void topological_sort() {
	queue<int> q;

	// 진입 차수가 0인 노드를 큐에 삽입
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		// 선택된 정점 큐에서 삭제
		int node = q.front();
		q.pop();

		// 선택된 정점에 부속된 모든 간선에 대해 간선의 수를 감소
		for (int i = 0; i < (int)adjList[node].size(); i++) {
			int next = adjList[node][i];
			degree[next]--;
			// 진입 차수가 0이 되면 해당 노드를 큐에 삽입
			if (degree[next] == 0) {
				q.push(next);
				// 현재 학기보다 +1한 값 저장
				semester[next] = semester[node] + 1;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	adjList = vector<vector<int>>(N+1, vector<int>(0, 0));
	degree = vector<int>(N + 1, 0);
	semester = vector<int>(N + 1, 1);

	// 인접리스트 만들기
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		adjList[from].push_back(to);
		degree[to]++; // 진입 차수 1만큼 증가
	}

	topological_sort();

	for (int i = 1; i <= N; i++)
		cout << semester[i] << " ";

	return 0;
}