#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
char board[20][20];
int coin[2][2];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0,0,-1,1 };
int answer = 999999999;

bool range_check(int x, int y) {
	if (x < 0 || x >= N || y < 0 || y >= M)
		return false;
	return true;
}

void dfs(int button, int x1, int y1, int x2, int y2) {
	// button�� ���� answer���� Ŀ���� ���� �� Ž���� �ʿ�X
	if (answer <= button) return;
	// ��ư�� 10������ ���� ���� ���
	if (button > 10) return;

	// ���� üũ
	if (!range_check(x1, y1)) {
		if (!range_check(x2, y2)) {
			// �� �� ������ ����ٸ�
			return;
		}
		answer = min(answer, button);
		return;
	}
	else if (!range_check(x2, y2)) {
		answer = min(answer, button);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int nx1 = x1 + dx[i];
		int ny1 = y1 + dy[i];
		int nx2 = x2 + dx[i];
		int ny2 = y2 + dy[i];
		
		// �� üũ
		if (board[nx1][ny1] == '#' && board[nx2][ny2] == '#')
			continue;
		else if(board[nx1][ny1] == '#')
			dfs(button + 1, x1, y1, nx2, ny2);
		else if(board[nx2][ny2] == '#')
			dfs(button + 1, nx1, ny1, x2, y2);
		else
			dfs(button + 1, nx1, ny1, nx2, ny2);
	}
}

int main() {
	cin >> N >> M;

	int idx = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			cin >> board[i][j];
			if (board[i][j] == 'o') {
				coin[idx][0] = i;
				coin[idx++][1] = j;
			}
		}

	dfs(0, coin[0][0], coin[0][1], coin[1][0], coin[1][1]);

	if (answer > 10) cout << -1;
	else cout << answer;

	return 0;
}