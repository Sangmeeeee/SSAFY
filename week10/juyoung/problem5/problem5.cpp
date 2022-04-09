#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <utility>
#define INF 1e9
using namespace std;

int N, M;
char maze[101][101];
int dist[101][101];
bool visited[101][101];
int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void dijkstra() {
	priority_queue<tuple<int, int, int>> pq;

	pq.push({ 0, 0, 0 }); // 벽 부순 개수, 행, 열
	dist[0][0] = 0;
	visited[0][0] = true;

	while (!pq.empty()) {
		int wall = -get<0>(pq.top());
		int y = get<1>(pq.top());
		int x = get<2>(pq.top());
		pq.pop();

		if (dist[y][x] < wall)
			continue;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

			int new_cost = wall + maze[ny][nx] - 48;
			if (new_cost < dist[ny][nx]) {
				dist[ny][nx] = new_cost;
				visited[ny][nx] = true;
				pq.push({ -new_cost, ny, nx });
			}
		}
	}
}

int main() {
	cin >> M >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> maze[i][j];
			dist[i][j] = INF;
		}
	}

	dijkstra();
	cout << dist[N - 1][M - 1];

	return 0;
}