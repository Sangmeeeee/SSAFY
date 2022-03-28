#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	vector<pair<int, int>> line;
	vector<int> dp;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		line.push_back({ a,b });
		dp.push_back(1);
	}

	sort(line.begin(), line.end());

	int answer = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i; j++) {
			if (line[j].second < line[i].second)
				dp[i] = max(dp[i], dp[j] + 1);
		}
		answer = max(answer, dp[i]);
	}

	cout << N - answer;
	return 0;
}