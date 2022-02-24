#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[51][51];
bool visited[51][51];
int sx, sy, dx, dy;
int dir_x[] = { -1,1,0,0 };
int dir_y[] = { 0,0,-1,1 };
// ȫ���� ó���ϱ� ���� ����
queue<pair<int, int>> water;
bool w_visited[51][51];

void bfs2() {
	// 1�ʵ��� �Ҿ ���� ó���ϱ� ���� size�� water ť ������ ����
	int size = water.size();

	// size��ŭ�� ȫ�� ó��
	for (int s = 0; s < size; s++) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();
		w_visited[x][y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			// ��� �ұ��̳� ���� ������� ����
			if (!w_visited[nx][ny] && map[nx][ny] != 'D' && map[nx][ny] != 'X') {
				w_visited[nx][ny] = true;
				map[nx][ny] = '*';
				water.push({ nx, ny });
			}
		}
	}
}

int bfs() {
	queue<pair<int, int>> q;
	q.push({ sx, sy });

	int time = 0;
	while (!q.empty()) {
		bfs2(); // ���ʸ��� ȫ�� ó��
		
		// ���� ť�� ����� �͵鿡 ���� ����ġ�� �̵� ���� ��� ����
		
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();
			visited[x][y] = true;

			for (int i = 0; i < 4; i++) {
				int nx = x + dir_x[i];
				int ny = y + dir_y[i];

				if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
				// ���̳� ���� ������� ����
				if (!visited[nx][ny] && map[nx][ny] != '*' && map[nx][ny] != 'X') {
					// ���� �湮 ��ġ�� ��� �ұ��̶�� return
					if (nx == dx && ny == dy)
						return time + 1;
					visited[nx][ny] = true;
					q.push({ nx, ny });
				}
			}
		}
		time++;
	}

	return -1;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == 'S') {
				sx = i; sy = j;
			} else if (map[i][j] == 'D') {
				dx = i; dy = j;
			}
			else if (map[i][j] == '*')
				water.push({ i,j });
		}

	int answer = bfs();
	if (answer == -1)
		cout << "KAKTUS";
	else
		cout << answer;

	return 0;
}