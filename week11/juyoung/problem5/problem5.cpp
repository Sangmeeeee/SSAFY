#include <iostream>
using namespace std;

int N; // ������ ����
int matrix[21][21];
bool noRoute[21][21];

int main() {
	// �Է�
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> matrix[i][j];

	// �÷��̵� �ͼ�
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (i == j || i == k || j == k) continue;
				// 1. �ѹ��� i���� j�� ���� �� = ���� 1��
				// 2. i���� k�� �� �� k���� j�� �̵��ϴ� �� = ���� 2��
				// 1�� �̵� �ð��� 2�� �̵� �ð����� �� ũ�ٸ�
				// ���� ������ �ּ��� �� ����.(=�Ұ���)
				if (matrix[i][j] > matrix[i][k] + matrix[k][j]) {
					cout << -1;
					return 0;
				}
				// 1�� �̵� �ð��� 2�� �̵� �ð��� ���ٸ�
				// matrix���� i->k->j�� ���� ����� �̵� �ð��� ����� ��.
				// �̶��� ������ ������ 2���̹Ƿ� ��Ʈ�� ���Խ�Ű�� �ʴ´�.
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
	
	// ���� ��Ŀ��� ����⿡ ��ο� ���� �ð��� ����Ǿ������Ƿ�
	// 2�� ���� ���� �������� �Ѵ�.
	cout << answer / 2;

	return 0;
}
