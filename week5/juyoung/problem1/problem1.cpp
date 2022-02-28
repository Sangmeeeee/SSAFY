#include <iostream>
#include <queue>
using namespace std;

int N;
queue<long long> q;

int main() {
	cin >> N;

	// N이 10보다 작은 수라면 N을 그대로 출력하고 종료
	if (N < 10) {
		cout << N;
		return 0;
	}

	// 최대 감소하는 수는 9876543210
	// 이 숫자는 10C1 + 10C2 + ... + 10C10 = 1022번째 숫자이므로 이후의 숫자는 -1 출력
	if (N > 1022) {
		cout << -1;
		return 0;
	}

	// queue에 한 자리 수 push
	for (int i = 1; i <= 9; i++)
		q.push(i);
	// 넣은 개수만큼 N에서 빼주기
	N -= 9;

	while (!q.empty()) {
		// queue에서 하나씩 꺼내며
		long long num = q.front();
		q.pop();
		
		// num의 일의 자리 수보다 작은 수들을 num에 붙이고 queue에 push
		for (int j = 0; j < num%10; j++) {
			// 만약 N-1이 0이라면 현재 num을 출력하고 종료
			if (--N <= 0) {
				cout << num * 10 + j;
				exit(0);
			}
			q.push(num * 10 + j);
		}
	}

	return 0;
}
