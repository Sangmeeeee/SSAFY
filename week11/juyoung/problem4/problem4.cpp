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
		// 각 건물에서 치킨집까지의 최소 왕복 시간을 저장하는 배열
		int minTime[101];

		// 만든 조합으로 해당 치킨집과 다른 건물들의 최소 왕복 시간을 저장
		for (int j = 1; j <= N; j++) {
			// 만약 치킨집으로 설정한 곳이면 거리 0으로 설정
			if (j == comb[0] || j == comb[1]) minTime[j] = 0;
			else {
				// 첫번째 치킨집과 두번째 치킨집 중 더 가까운 곳의
				// 최소 왕복 시간을 저장
				minTime[j] = min(matrix[comb[0]][j], matrix[comb[1]][j]) * 2;
			}
		}

		int timeSum = 0;
		for (int i = 1; i <= N; i++) {
			timeSum += minTime[i];
		}

		// 현재 최소 왕복 시간보다 더 작으면 건물 번호 및 왕복 시간 합 갱신
		// 문제에서 건물의 조합이 다양하게 가능하면 번호가 더 작은 것을 출력하라고 했으므로
		// >=가 아닌 >인 경우에만 수행한다.
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

	// 플로이드 와샬
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