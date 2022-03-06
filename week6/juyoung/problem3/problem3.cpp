#include <iostream>
using namespace std;

int N, M, r, c, d;
int map[50][50];
bool visited[50][50];
int dy[] = { -1, 0, 1, 0 }; // �ϵ�����
int dx[] = { 0, 1, 0, -1 };
int answer = 0;

void clean(int y, int x, int dir) {
	while (1) {
		if(!visited[y][x]) answer++;
		visited[y][x] = true;

		// û�� ���� ����
		bool isCleaned = false;

		for (int i = 1; i <= 4; i++) {
			// dy dx���� �������� ������ �ǵ���
			int nd = (dir + 4 - i) % 4;
			int ny = y + dy[nd];
			int nx = x + dx[nd];

			// b. û���� ������ ���ٸ� ���ư���.
			if (visited[ny][nx] || map[ny][nx] == 1) continue;

			isCleaned = true;
			y = ny; x = nx; dir = nd;
			break;
		}

		// c, d. �� ���� ��� �̹� û�ҵ� ���¶��
		if (!isCleaned) {
			// ���� �ٶ󺸴� ������ �ݴ�
			int bd = (dir + 2) % 4;
			int by = y + dy[bd];
			int bx = x + dx[bd];

			// d. ������ �� ���ٸ� �ߴ��Ѵ�.
			if (map[by][bx] == 1)
				break;

			// c. ������ �� �ִٸ� ������ �����ϰ� �����Ѵ�.
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