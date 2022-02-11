#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
	int answer = 0;
	priority_queue<long long, vector<long long>, greater<long long>> pq;

	for (int i = 0; i < (int)scoville.size(); i++)
		pq.push(scoville[i]);

	while (pq.size() > 1 && pq.top() < K) {
		long long a = pq.top();
		pq.pop();
		long long b = pq.top();
		pq.pop();
		pq.push(a + b * 2);
		answer++;
	}

	if (pq.top() < K) return -1;

	return answer;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, K;
	vector<int> scoville;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		scoville.push_back(input);
	}
	cin >> K;

	cout << solution(scoville, K);

	return 0;
}