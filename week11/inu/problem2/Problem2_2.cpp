#include <iostream>
#define INF 10000
using namespace std;

int N, M, R;
int graph[101][101];
int item[101];
int maxItem = 0;

void floyd() {
	for (int i = 1; i <= N; i++)
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

	cin >> N >> M >> R;
	
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			graph[i][j] = INF;

	for (int i = 1; i <= N; i++)
		cin >> item[i];

	for (int i = 0; i < R; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		graph[a][b] = l;
		graph[b][a] = l;
	}

	floyd();

	for (int i = 1; i <= N; i++) {
		int itemCnt = 0;
		for (int j = 1; j <= N; j++) {
			if (graph[i][j] <= M)
				itemCnt += item[j];
		}
		maxItem = itemCnt > maxItem ? itemCnt : maxItem;
	}

	cout << maxItem;

	return 0;
}