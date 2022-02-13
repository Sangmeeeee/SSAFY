#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	cin >> T;

	while (T--) {
		int K;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		long long answer = 0;

		cin >> K;
		for (int i = 0; i < K; i++) {
			int novel;
			cin >> novel;
			pq.push(novel);
		}

		while (pq.size() > 1) {
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			pq.push(a + b);
			answer += a + b;
		}

		cout << answer << "\n";
	}
}