#include <iostream>
#include <vector>
#define vvi vector<vector<int>>
using namespace std;

int N;
long long B;
vvi A; // �ʱ� ��� ��

vvi calculate(vvi a, vvi b) {
	vvi temp(N, vector<int>(N, 0));

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				temp[i][j] += a[k][j] * b[i][k];
				temp[i][j] %= 1000;
			}
		}
	}

	return temp;
}

vvi recur(vvi matrix, long long exp) {
	// ������ 1�̸� �ʱ� ��� �� return
	if (exp == 1)
		return matrix;

	// ������ 2�� ������ ��������� ȣ��
	vvi arr = recur(matrix, exp / 2);
	// ��� ���� ��� 
	arr = calculate(arr, arr);

	// Ȧ����� A^1 �ѹ� �� ���ϱ�
	if (exp % 2 == 1)
		arr = calculate(arr, A);

	return arr;
}

int main() {
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		vector<int> temp;
		for (int j = 0; j < N; j++) {
			int input;
			cin >> input;
			temp.push_back(input%1000);
		}
		A.push_back(temp);
	}

	A = recur(A, B);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cout << A[i][j] << " ";
		cout << "\n";
	}

	return 0;
}