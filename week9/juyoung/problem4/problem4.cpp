#include <iostream>
using namespace std;

int N, K;
int dp[1001][1001];

int main() {
	cin >> N >> K;

	for (int i = 0; i <= N; i++) {
		dp[0][i] = 1;
		dp[1][i] = i;
	}

	for (int i = 2; i <= K; i++) {
		for (int j = 2; j <= N; j++) {
			dp[i][j] = (dp[i - 1][j - 2] + dp[i][j - 1]) % 1000000003;
		}
	}

	cout << (dp[K - 1][N - 3] + dp[K][N - 1]) % 1000000003;
	return 0;
}