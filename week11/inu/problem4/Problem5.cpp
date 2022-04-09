#include <iostream>
#include <vector>
#include <limits.h>
#include <string>
#define INF 500000
using namespace std;

int N, M;
int graph[101][101];
int minTime = INT_MAX;
pair<int, int> building;

void floyd() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
}

int chicken(int c1, int c2) {
	int sum = 0;
	for (int i = 1; i <= N; i++)
		sum += min(graph[i][c1], graph[i][c2]);
	return sum * 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			graph[i][j] = i == j ? 0 : INF;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	floyd();

	for (int i = 1; i < N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int time = chicken(i, j);
			if (time < minTime) {
				minTime = time;
				building = { i, j };
			}
			else if (time == minTime) {
				if (i < building.first)
					building = { i, j };
				else if (i == building.first) {
					if (j < building.second)
						building = { i, j };
				}
			}
		}
	}

	cout << building.first << ' ';
	cout << building.second << ' ';
	cout << minTime;

	return 0;
}