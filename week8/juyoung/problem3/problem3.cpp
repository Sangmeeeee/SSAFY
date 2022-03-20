#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N, M;
vector<vector<int>> adjList;	// ��������Ʈ
vector<int> degree;				// ���� ����
vector<int> semester;			// �б� ����

void topological_sort() {
	queue<int> q;

	// ���� ������ 0�� ��带 ť�� ����
	for (int i = 1; i <= N; i++) {
		if (degree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		// ���õ� ���� ť���� ����
		int node = q.front();
		q.pop();

		// ���õ� ������ �μӵ� ��� ������ ���� ������ ���� ����
		for (int i = 0; i < (int)adjList[node].size(); i++) {
			int next = adjList[node][i];
			degree[next]--;
			// ���� ������ 0�� �Ǹ� �ش� ��带 ť�� ����
			if (degree[next] == 0) {
				q.push(next);
				// ���� �б⺸�� +1�� �� ����
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

	// ��������Ʈ �����
	for (int i = 0; i < M; i++) {
		int from, to;
		cin >> from >> to;
		adjList[from].push_back(to);
		degree[to]++; // ���� ���� 1��ŭ ����
	}

	topological_sort();

	for (int i = 1; i <= N; i++)
		cout << semester[i] << " ";

	return 0;
}