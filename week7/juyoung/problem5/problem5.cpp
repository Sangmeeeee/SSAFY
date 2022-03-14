#include <iostream>
#include <vector>
#define vvi vector<vector<int>>
using namespace std;

int N;
long long B;
vvi A; // 초기 행렬 값

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
	// 지수가 1이면 초기 행렬 값 return
	if (exp == 1)
		return matrix;

	// 지수를 2로 나누며 재귀적으로 호출
	vvi arr = recur(matrix, exp / 2);
	// 행렬 제곱 계산 
	arr = calculate(arr, arr);

	// 홀수라면 A^1 한번 더 곱하기
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