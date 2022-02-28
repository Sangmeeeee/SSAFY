#include <iostream>
#include <queue>
using namespace std;

int R, C;
char map[51][51];
bool visited[51][51];
int sx, sy, dx, dy;
int dir_x[] = { -1,1,0,0 };
int dir_y[] = { 0,0,-1,1 };
// 홍수를 처리하기 위한 변수
queue<pair<int, int>> water;
bool w_visited[51][51];

void bfs2() {
	// 1초동안 불어날 물만 처리하기 위해 size에 water 큐 사이즈 저장
	int size = water.size();

	// size만큼만 홍수 처리
	for (int s = 0; s < size; s++) {
		int x = water.front().first;
		int y = water.front().second;
		water.pop();
		w_visited[x][y] = true;

		for (int i = 0; i < 4; i++) {
			int nx = x + dir_x[i];
			int ny = y + dir_y[i];
			
			if (nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
			// 비버 소굴이나 돌은 통과하지 못함
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
		bfs2(); // 매초마다 홍수 처리
		
		// 현재 큐에 저장된 것들에 대한 고슴도치의 이동 가능 경로 저장
		
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
				// 물이나 돌은 통과하지 못함
				if (!visited[nx][ny] && map[nx][ny] != '*' && map[nx][ny] != 'X') {
					// 다음 방문 위치가 비버 소굴이라면 return
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