#include <iostream>
#include <algorithm>
#define INF 1e9
using namespace std;

int N, M;
int matrix[101][101];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		if (matrix[a][b] != 0)
			matrix[a][b] = min(matrix[a][b], c);
		else
			matrix[a][b] = c;
	}

	// �ڱ��ڽ��� �ƴϸ鼭 ���� 0�̸� ������� �ʾҴٴ� �ǹ��̹Ƿ� ����� ū �� ����
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j && matrix[i][j] == 0)
				matrix[i][j] = INF;
		}
	}

	// i���� j�� ���� ��� vs i���� k�� ���� ���+k���� j�� ���� ���
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (matrix[i][j] > matrix[i][k] + matrix[k][j])
					matrix[i][j] = matrix[i][k] + matrix[k][j];

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++)
			// ������� ���� ���� 0���� �������� ��
			if (matrix[i][j] == INF)
				cout << 0 << " ";
			else
				cout << matrix[i][j] << " ";
		cout << "\n";
	}

	return 0;
}