#include <iostream>
#include <cmath>
using namespace std;

char gear[4][8];
int K;

void rotate(int num, int dir) {
	if (dir == 1) { // 시계 방향
		int temp = gear[num][7];
		for (int i = 7; i > 0; i--)
			gear[num][i] = gear[num][i - 1];
		gear[num][0] = temp;
	}
	else { // 반시계 방향
		int temp = gear[num][0];
		for (int i = 0; i < 7; i++)
			gear[num][i] = gear[num][i + 1];
		gear[num][7] = temp;
	}
}

int main() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 8; j++)
			cin >> gear[i][j];
	cin >> K;

	while (K--) {
		int num, dir;
		cin >> num >> dir;
		num -= 1;

		// 왼쪽 톱니바퀴
		int prev = num - 1;
		int curr = num;
		// 몇번까지 돌려야 하는지 체크
		while (prev > -1) {
			if (gear[prev][2] != gear[curr][6]) {
				curr = prev;
				prev--;
			}
			else
				break;
		}

		// 돌려야 하는 톱니바퀴들 돌리기
		int p_dir = -dir;
		for (int i = num - 1; i > prev; i--) {
			rotate(i, p_dir);
			p_dir = -p_dir;
		}

		// 오른쪽 톱니바퀴
		curr = num;
		int next = num + 1;
		while (next < 4) {
			if (gear[curr][2] != gear[next][6]) {
				curr = next;
				next++;
			}
			else
				break;
		}

		int n_dir = -dir;
		for (int i = num+1; i < next; i++) {
			rotate(i, n_dir);
			n_dir = -n_dir;
		}

		rotate(num, dir);
	}
	
	int answer = 0;
	for (int i = 0; i < 4; i++)
		if (gear[i][0] == '1')
			answer += (int)pow(2, i);
	
	cout << answer;

	return 0;
}