#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main() {
	int N, K;
	vector<int> sum;
	map<int, long long> m;
	long long answer = 0;

	cin >> N >> K;
	
	// 누적합 저장
	sum.push_back(0);
	for (int i = 1; i <= N; i++) {
		int input;

		cin >> input;
		sum.push_back(sum[i-1] + input);
	}

	for (int i = 1; i <= N; i++) {
		if (sum[i] == K)
			answer++;
		answer += m[sum[i] - K];
		m[sum[i]]++;
	}

	cout << answer;

	return 0;
}