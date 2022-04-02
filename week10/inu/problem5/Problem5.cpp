#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

class pos {
public:
	int wall;
	int x, y;

	pos() { }

	pos(int x, int y, int wall) {
		this->x = x;
		this->y = y;
		this->wall = wall;
	}
};

int N, M;
char map[100][100];
int wall[100][100];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> M >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			wall[i][j] = INT_MAX;
		}
	}
	
	queue<pos> q;
	wall[0][0] = 0;
	q.push(pos(0, 0, 0));
	while (!q.empty()) {
		pos p = q.front();
		q.pop();

		if (p.wall < wall[p.x][p.y]) continue;

		for (int i = 0; i < 4; i++) {
			int x = p.x + dx[i];
			int y = p.y + dy[i];

			if (x < 0 || x >= N || y < 0 || y >= M)
				continue;

			if (wall[p.x][p.y] + (map[x][y] - 48) < wall[x][y]) {
				wall[x][y] = wall[p.x][p.y] + (map[x][y] - 48);
				q.push(pos(x, y, wall[x][y]));
			}
		}
	}

	cout << wall[N - 1][M - 1];

	return 0;
}