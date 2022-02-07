#include <iostream>
#include <queue>
#include <functional>
using namespace std;

int main() {
	int n, card, answer = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card;
		pq.push(card);
	}

	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		answer += a + b;
		pq.push(a + b);
	}

	cout << answer;

	return 0;
}