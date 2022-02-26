#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <tuple>
#define INF 999999999
using namespace std;

int N, M;
vector<vector<int>> map;
vector<vector<vector<int>>> visited;
int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int bfs() {
	queue<tuple<int, int, int>> q;
	q.push({ 0, 0, 1 });
	visited[0][0][1] = 1;

	while (!q.empty()) {
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int isBroken = get<2>(q.front());
		q.pop();

		// N과 M이 1인 경우를 위해 for문 밖에 배치
		if (x == N - 1 && y == M - 1)
			return visited[x][y][isBroken];

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
			if (map[nx][ny] == 1 && isBroken) {
				q.push({ nx, ny, 0 });
				visited[nx][ny][isBroken - 1] = visited[x][y][isBroken] + 1;
			}
			else if (map[nx][ny] == 0 && visited[nx][ny][isBroken] == 0) {
				q.push({ nx, ny, isBroken });
				visited[nx][ny][isBroken] = visited[x][y][isBroken] + 1;
			}
		}
	}

	return -1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	map.assign(N, vector<int>(M, 0));
	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++)
			map[i][j] = temp[j] - 48;
	}
	
	visited.assign(N, vector<vector<int>>(M, vector<int>(2, 0)));
	cout << bfs();

	return 0;
}