#include <iostream>
#define INF 3000

using namespace std;

int N;
int sum = 0;
int graph[21][21];

bool floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (k != i && i != j && k != j) {
					if (graph[i][k] + graph[k][j] < graph[i][j]) {
						if (graph[i][j] == INF)
							continue;
						return false;
					}
					else if (graph[i][k] + graph[k][j] == graph[i][j])
						graph[i][j] = INF;
				}
			}
		}
	}			
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> graph[i][j];

	if (floyd()) {
		for (int i = 1; i < N; i++)
			for (int j = i + 1; j <= N; j++)
				if(graph[i][j] != INF)
					sum += graph[i][j];
	}
	else
		sum = -1;
	
	cout << sum;

	return 0;
}