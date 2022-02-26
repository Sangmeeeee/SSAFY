#include <iostream>
#include <algorithm>
using namespace std;

int N, L, R, X;
int A[15];		// 문제의 난이도
bool isSelected[15];
int answer = 0;

void dfs(int cnt) {
	if (cnt == N) {
		long long sum = 0;
		int max_value = -999999999;
		int min_value = 999999999;
		for (int i = 0; i < N; i++) {
			if (isSelected[i]) {
				sum += A[i];
				max_value = max(max_value, A[i]);
				min_value = min(min_value, A[i]);
			}
		}
		if (!(L <= sum && sum <= R)) return;
		if (max_value - min_value < X) return;
		answer++;
		return;
	}

	isSelected[cnt] = true;
	dfs(cnt + 1);
	isSelected[cnt] = false;
	dfs(cnt + 1);
}

int main() {
	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++)
		cin >> A[i];
	dfs(0);
	cout << answer;
	return 0;
}