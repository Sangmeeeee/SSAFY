#include <iostream>
#include <vector>

using namespace std;

int N, M, K;
int x, y;
int map[20][20];
int dice[] = { 0, 0, 0, 0, 0, 0 };
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

void roll(int dir) {
	int temp = 0;

	switch (dir) {
	case 1: // µ¿
		temp = dice[4];
		dice[4] = dice[3];
		dice[3] = dice[5];
		dice[5] = dice[1];
		dice[1] = temp;
		break;
	case 2: // ¼­
		temp = dice[5];
		dice[5] = dice[3];
		dice[3] = dice[4];
		dice[4] = dice[1];
		dice[1] = temp;
		break;
	case 3: // ºÏ
		temp = dice[0];
		for (int i = 1; i <= 3; i++)
			dice[i - 1] = dice[i];
		dice[3] = temp;
		break;
	case 4: // ³²
		temp = dice[3];
		for (int i = 2; i >= 0; i--)
			dice[i + 1] = dice[i];
		dice[0] = temp;
		break;
	}

	if (map[x][y] == 0)
		map[x][y] = dice[3];
	else {
		dice[3] = map[x][y];
		map[x][y] = 0;
	}
		

	cout << dice[1] << '\n';
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M >> x >> y >> K;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		int dir;
		cin >> dir;
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M)
			continue;

		x = nx; y = ny;
		roll(dir);
	}

	return 0;
}