#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int N, M;
int ans = INT_MAX;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
char board[20][20];

int checkPos(int x, int y) {
	// 보드에서 떨어짐
	if (x < 0 || x >= N || y < 0 || y >= M)
		return 0;
	// 이동
	if (board[x][y] == '.' || board[x][y] == 'o') {
		return 1;
	}		
	// 벽
	return 2;
}

void moveCoins(int x1, int y1, int x2, int y2, int cnt, int d) {
	// 횟수가 ans보다 크거나 10보다 크면 종료
	if (cnt > ans || cnt > 10)
		return;

	int dx1 = x1 + dx[d], dy1 = y1 + dy[d];
	int dx2 = x2 + dx[d], dy2 = y2 + dy[d];
	int m1 = checkPos(dx1, dy1);
	int m2 = checkPos(dx2, dy2);

	// 둘 다 범위에서 벗어나거나 둘 다 벽에 막히면 종료
	if (m1 == 0 && m2 == 0 || m1 == 2 && m2 == 2)
		return;

	// 둘 중 하나만 범위에서 벗어나면 ans 갱신하고 종료
	if (m1 == 0 || m2 == 0) {
		ans = min(ans, cnt);
		return;
	}

	// 벽이면 좌표 원래대로
	if (m1 == 2) { dx1 = x1; dy1 = y1; }
	if (m2 == 2) { dx2 = x2; dy2 = y2; }

	for (int i = 0; i < 4; i++)
		moveCoins(dx1, dy1, dx2, dy2, cnt + 1, i);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	vector<pair<int, int>> coin;
	for(int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o')
				coin.push_back({ i, j });
		}
	
	for (int i = 0; i < 4; i++) {
		int x1 = coin[0].first, y1 = coin[0].second;
		int x2 = coin[1].first, y2 = coin[1].second;
		moveCoins(x1, y1, x2, y2, 1, i);
	}
	
	// 모두 10회 이상이면 ans값 변화 X
	if (ans == INT_MAX)
		ans = -1;

	cout << ans;

	return 0;
}