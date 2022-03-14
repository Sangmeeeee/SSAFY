#include <iostream>
#include <algorithm>
using namespace std;

int N, K;
int people[50001];
int dp[4][50000];

int main() {
	cin >> N;
	people[0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> people[i];
	cin >> K;

	// 누적합 구하기
	for (int i = 2; i <= N; i++)
		people[i] += people[i - 1];

	// dp배열 채우기
	for (int j = K; j <= N; j++)
		dp[1][j] = max(dp[1][j - 1], people[j] - people[j - K]);
	for(int j=K*2; j<=N; j++)
		dp[2][j] = max(dp[2][j - 1], people[j] - people[j - K] + dp[1][j - K]);
	for (int j = K * 3; j <= N; j++)
		dp[3][j] = max(dp[3][j - 1], people[j] - people[j - K] + dp[2][j - K]);
	
	cout << dp[3][N];
	
	return 0;
}