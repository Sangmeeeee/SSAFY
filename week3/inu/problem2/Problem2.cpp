#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int T, K, c;
	cin >> T;
	for (int i = 0; i < T; i++) {
		long long sum = 0;
		priority_queue<long long, vector<long long>, greater<>> pq;

		cin >> K;
		for (int i = 0; i < K; i++) {
			cin >> c;
			pq.push(c);
		}

		for (int i = 0; i < K - 1; i++) {
			long long a = pq.top(); pq.pop();
			long long b = pq.top(); pq.pop();
			sum += a + b;
			pq.push(a + b);
		}

		cout << sum << '\n';
	}

	return 0;
}