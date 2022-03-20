#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
int inEdge[1001];
int ans[1001];
bool visited[1001];
vector<vector<int>> subject;
queue<int> q;

void topological_sort() {
	int semester = 1;
	
	while (!q.empty()) {
		int qsize = q.size();
		
		for (int i = 0; i < qsize; i++) {
			int u = q.front(); q.pop();
			ans[u] = semester;

			for (int j = 0; j < (int)subject[u].size(); j++) {
				if (--inEdge[subject[u][j]] == 0)
					q.push(subject[u][j]);
			}
		}
		
		semester++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	
	subject.assign(N + 1, vector<int>());
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		subject[a].push_back(b);
		inEdge[b]++;
	}

	for (int i = 1; i <= N; i++)
		if (!inEdge[i])
			q.push(i);

	topological_sort();

	for (int i = 1; i <= N; i++)
		cout << ans[i] << ' ';

	return 0;
}