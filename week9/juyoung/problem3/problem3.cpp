#include <iostream>
using namespace std;

int N;
long long dp[2][1000001];

int main() {
	dp[0][0] = 0;
	dp[0][1] = 2;
	dp[0][2] = 7;
	dp[1][2] = 1;

	cin >> N;

	for (int i = 3; i <= N; i++) {
		dp[1][i] = (dp[0][i - 3] + dp[1][i - 1]) % 1000000007;
		dp[0][i] = (2 * dp[0][i - 1] + 3 * dp[0][i - 2] + 2 * dp[1][i]) % 1000000007;
	}

	cout << dp[0][N];

	return 0;
}