#include <iostream>
using namespace std;

int N; // 도시의 개수
int matrix[21][21];
bool noRoute[21][21];

int main() {
	// 입력
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	// 플로이드 와샬
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j || i == k || j == k) continue;
				// 1. 한번에 i에서 j로 가는 것 = 도로 1개
				// 2. i에서 k로 간 후 k에서 j로 이동하는 것 = 도로 2개
				// 1의 이동 시간이 2의 이동 시간보다 더 크다면
				// 도로 개수가 최소일 수 없다.(=불가능)
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					cout << -1;
					return 0;
				}
				// 1의 이동 시간과 2의 이동 시간이 같다면
				// matrix에는 i->k->j로 가는 경로의 이동 시간이 저장된 것.
				// 이때는 도로의 개수가 2개이므로 루트에 포함시키지 않는다.
				if (matrix[i][j] == matrix[i][k] + matrix[k][j])
					noRoute[i][j] = true;
			}
		}
	}

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (noRoute[i][j]) continue;
			answer += matrix[i][j];
		}
	}
	
	// 인접 행렬에는 양방향에 모두에 대한 시간이 저장되어있으므로
	// 2로 나눈 값을 출력해줘야 한다.
	cout << answer / 2;

	return 0;
}
