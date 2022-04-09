#include <iostream>
#include <algorithm>
#define INF 999999
using namespace std;

int N, M;
int matrix[101][101];
int comb[2];
int num1, num2, answer = INF;

void makeComb(int idx, int cnt) {
	if (cnt == 2) {
		// �� �ǹ����� ġŲ�������� �ּ� �պ� �ð��� �����ϴ� �迭
		int minTime[101];

		// ���� �������� �ش� ġŲ���� �ٸ� �ǹ����� �ּ� �պ� �ð��� ����
		for (int j = 1; j <= N; j++) {
			// ���� ġŲ������ ������ ���̸� �Ÿ� 0���� ����
			if (j == comb[0] || j == comb[1]) minTime[j] = 0;
			else {
				// ù��° ġŲ���� �ι�° ġŲ�� �� �� ����� ����
				// �ּ� �պ� �ð��� ����
				minTime[j] = min(matrix[comb[0]][j], matrix[comb[1]][j]) * 2;
			}
		}

		int timeSum = 0;
		for (int i = 1; i <= N; i++) {
			timeSum += minTime[i];
		}

		// ���� �ּ� �պ� �ð����� �� ������ �ǹ� ��ȣ �� �պ� �ð� �� ����
		// �������� �ǹ��� ������ �پ��ϰ� �����ϸ� ��ȣ�� �� ���� ���� ����϶�� �����Ƿ�
		// >=�� �ƴ� >�� ��쿡�� �����Ѵ�.
		if (answer > timeSum) {
			num1 = comb[0];
			num2 = comb[1];
			answer = timeSum;
		}

		return;
	}
	
	for (int i = idx; i <= N; i++) {
		comb[cnt] = i;
		makeComb(i + 1, cnt + 1);
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		matrix[A][B] = 1;
		matrix[B][A] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			if (i != j && matrix[i][j] == 0)
				matrix[i][j] = INF;
	}

	// �÷��̵� �ͼ�
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (matrix[i][j] > matrix[i][k] + matrix[k][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];
			}
		}
	}

	makeComb(1, 0);

	cout << num1 << " " << num2 << " " << answer;
	return 0;
}