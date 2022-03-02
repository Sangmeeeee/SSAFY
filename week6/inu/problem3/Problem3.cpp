#include <iostream>
#include <queue>

using namespace std;

typedef pair<int, int> pos;

int map[50][50];
bool clean[50][50];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int back_dir[] = { 2, 3, 0, 1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int x, y, dir;
	
	cin >> N >> M;
	cin >> x >> y >> dir;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int answer = 1;
	int cnt = 0;
	clean[x][y] = true;

	while (1) {
		if ((dir - 1) == -1)
			dir = 3;
		else
			dir--;

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;

		// 빈칸이고 청소 안한 곳이면 이동
		if (map[nx][ny] == 0 && !clean[nx][ny]) {
			clean[nx][ny] = true;
			x = nx;
			y = ny;
			cnt = 0;
			answer++;
		}
		else
			cnt++;

		if (cnt == 4) {
			nx = x + dx[back_dir[dir]];
			ny = y + dy[back_dir[dir]];

			if (nx < 0 || nx >= N || ny < 0 || ny >= M || map[nx][ny] == 1)
				break;

			x = nx;
			y = ny;
			cnt = 0;
		}
	}

	cout << answer;

	return 0;
}