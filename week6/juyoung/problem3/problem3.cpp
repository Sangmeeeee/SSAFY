#include <iostream>
using namespace std;

int N, M, r, c, d;
int map[50][50];
bool visited[50][50];
int dy[] = { -1, 0, 1, 0 }; // 북동남서
int dx[] = { 0, 1, 0, -1 };
int answer = 0;

void clean(int y, int x, int dir) {
	while (1) {
		if(!visited[y][x]) answer++;
		visited[y][x] = true;

		// 청소 여부 저장
		bool isCleaned = false;

		for (int i = 1; i <= 4; i++) {
			// dy dx에서 서남동북 순으로 되도록
			int nd = (dir + 4 - i) % 4;
			int ny = y + dy[nd];
			int nx = x + dx[nd];

			// b. 청소할 공간이 없다면 돌아간다.
			if (visited[ny][nx] || map[ny][nx] == 1) continue;

			isCleaned = true;
			y = ny; x = nx; dir = nd;
			break;
		}

		// c, d. 네 방향 모두 이미 청소된 상태라면
		if (!isCleaned) {
			// 현재 바라보는 방향의 반대
			int bd = (dir + 2) % 4;
			int by = y + dy[bd];
			int bx = x + dx[bd];

			// d. 후진할 수 없다면 중단한다.
			if (map[by][bx] == 1)
				break;

			// c. 후진할 수 있다면 방향은 유지하고 후진한다.
			y = by; x = bx;
		}
	}
}

int main() {
	cin >> N >> M >> r >> c >> d;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	clean(r, c, d);

	cout << answer;

	return 0;
}