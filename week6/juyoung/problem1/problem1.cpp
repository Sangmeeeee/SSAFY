#include <iostream>
using namespace std;

int N, M, x, y, K;
int map[20][20];
int dice[6] = { 0,0,0,0,0,0 };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> x >> y >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];
	
	int idx = 1;
	int check = false;
	for (int i = 0; i < K; i++) {
		int input;
		cin >> input;

		// ���� ��ġ ����
		int nx = x + dx[input - 1];
		int ny = y + dy[input - 1];

		if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;

		// ��ɿ� ���� �������� �� ��ġ swap
		if (input == 1) { // ����
			swap(dice[0], dice[2]);
			swap(dice[0], dice[3]);
			swap(dice[3], dice[5]);
		}
		else if (input == 2) { // ����
			swap(dice[0], dice[3]);
			swap(dice[0], dice[5]);
			swap(dice[0], dice[2]);
		}
		else if (input == 3) { // ����
			swap(dice[0], dice[1]);
			swap(dice[0], dice[5]);
			swap(dice[0], dice[4]);
		}
		else { // ����
			swap(dice[0], dice[4]);
			swap(dice[0], dice[5]);
			swap(dice[0], dice[1]);
		}

		// ĭ�� �����ִ� ���� 0�̸� �ֻ��� �ٴڸ��� ���� ����
		if (map[nx][ny] == 0)
			map[nx][ny] = dice[5];
		// 0�� �ƴ� ��� ĭ�� ���� �ִ� ���� �ֻ��� �ٴڸ鿡 ����
		else {
			dice[5] = map[nx][ny];
			map[nx][ny] = 0;
		}

		x = nx;
		y = ny;

		cout << dice[0] << "\n";
	}

	return 0;
}