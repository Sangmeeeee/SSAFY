#include <iostream>
#include <queue>
using namespace std;

int N;
queue<long long> q;

int main() {
	cin >> N;

	// N�� 10���� ���� ����� N�� �״�� ����ϰ� ����
	if (N < 10) {
		cout << N;
		return 0;
	}

	// �ִ� �����ϴ� ���� 9876543210
	// �� ���ڴ� 10C1 + 10C2 + ... + 10C10 = 1022��° �����̹Ƿ� ������ ���ڴ� -1 ���
	if (N > 1022) {
		cout << -1;
		return 0;
	}

	// queue�� �� �ڸ� �� push
	for (int i = 1; i <= 9; i++)
		q.push(i);
	// ���� ������ŭ N���� ���ֱ�
	N -= 9;

	while (!q.empty()) {
		// queue���� �ϳ��� ������
		long long num = q.front();
		q.pop();
		
		// num�� ���� �ڸ� ������ ���� ������ num�� ���̰� queue�� push
		for (int j = 0; j < num%10; j++) {
			// ���� N-1�� 0�̶�� ���� num�� ����ϰ� ����
			if (--N <= 0) {
				cout << num * 10 + j;
				exit(0);
			}
			q.push(num * 10 + j);
		}
	}

	return 0;
}
