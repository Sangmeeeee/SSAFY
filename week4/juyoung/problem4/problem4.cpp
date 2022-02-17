#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

vector<int> adjList[2000];
bool visited[2000];

void dfs(int node, int depth) {
	if (depth == 5) {
		cout << 1;
		exit(0);
	}

	for (int i = 0; i < (int)adjList[node].size(); i++) {
		int next = adjList[node][i];
		if (visited[next]) continue;
		visited[next] = true;
		dfs(next, depth + 1);
		visited[next] = false;
	}
}

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adjList[a].push_back(b);
		adjList[b].push_back(a);
	}
	
	for (int i = 0; i < N; i++)
		dfs(i, 1);

	cout << 0;
	return 0;
}