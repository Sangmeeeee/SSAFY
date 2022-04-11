#include <iostream>
#include <vector>
#define INF 10000001

using namespace std;

int N, M;
int graph[101][101];

void floyd() {
	for (int i = 0; i <= N; i++)
		graph[i][i] = 0;

	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			graph[i][j] = INF;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if(c < graph[a][b])
			graph[a][b] = c;
	}

	floyd();

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (graph[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << graph[i][j] << ' ';
		cout << '\n';
	}

	return 0;
}