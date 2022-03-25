#include <iostream>
using namespace std;

int N;
int dp[31];

int main() {
	cin >> N;
	
	dp[2] = 3;
	dp[4] = dp[2] * dp[2] + 2;
	
	for (int i = 6; i <= N; i += 2) {
		int sum = 0;
		for (int j = i - 4; j >= 2; j -= 2) {
			sum += dp[j];
		}
		dp[i] = dp[i - 2] * dp[2] + 2 * sum + 2;
	}

	cout << dp[N];
	return 0;
}