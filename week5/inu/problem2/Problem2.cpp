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
	// ���忡�� ������
	if (x < 0 || x >= N || y < 0 || y >= M)
		return 0;
	// �̵�
	if (board[x][y] == '.' || board[x][y] == 'o') {
		return 1;
	}		
	// ��
	return 2;
}

void moveCoins(int x1, int y1, int x2, int y2, int cnt, int d) {
	// Ƚ���� ans���� ũ�ų� 10���� ũ�� ����
	if (cnt > ans || cnt > 10)
		return;

	int dx1 = x1 + dx[d], dy1 = y1 + dy[d];
	int dx2 = x2 + dx[d], dy2 = y2 + dy[d];
	int m1 = checkPos(dx1, dy1);
	int m2 = checkPos(dx2, dy2);

	// �� �� �������� ����ų� �� �� ���� ������ ����
	if (m1 == 0 && m2 == 0 || m1 == 2 && m2 == 2)
		return;

	// �� �� �ϳ��� �������� ����� ans �����ϰ� ����
	if (m1 == 0 || m2 == 0) {
		ans = min(ans, cnt);
		return;
	}

	// ���̸� ��ǥ �������
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
	
	// ��� 10ȸ �̻��̸� ans�� ��ȭ X
	if (ans == INT_MAX)
		ans = -1;

	cout << ans;

	return 0;
}