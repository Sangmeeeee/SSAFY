#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	priority_queue<int, vector<int>, greater<int>> pq;
	vector<int> v;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int c;
		cin >> c;
		pq.push(c);
	}

	if (pq.size() == 1) {
		cout << pq.top();
		return 0;
	}

	int sum = 0;
	for (int i = 0; i < N - 1; i++) {
		int p = pq.top(); pq.pop();
		int q = pq.top(); pq.pop();
		sum += p + q;
		pq.push(p + q);
	}

	cout << sum;

	return 0;
}