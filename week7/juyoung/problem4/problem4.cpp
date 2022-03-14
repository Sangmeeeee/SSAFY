#include <iostream>
using namespace std;

int main() {
	long long N;
	long long len = 0;	// ��ü ������ ����
	int temp = 3;		// o�� k+2���� ������ ����

	cin >> N;

	while (1) {
		len = len * 2 + temp;
		if (N <= len) break;
		temp++;
	}

	while (1) {
		long long prev = (len - temp) / 2; // ���� ���ڿ��� ����

		// N�� ���� S(k=1) ���� �ȿ� �ִٸ�
		if (N <= prev) {
			len = prev;
			temp--;
		}
		// N�� o�� k+2���� ���� �ȿ� �ִٸ�
		else if (prev < N && N <= prev + temp) {
			if (N - prev == 1) cout << 'm';
			else cout << 'o';
			break;
		}
		// N�� ���� S(k-1) ���� �ȿ� �ִٸ�
		else if (prev + temp < N) {
			N -= prev + temp;
			len = prev;
			temp--;
		}
	}

	return 0;
}