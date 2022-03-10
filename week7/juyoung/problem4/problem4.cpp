#include <iostream>
using namespace std;

int main() {
	long long N;
	long long len = 0;	// 전체 수열의 길이
	int temp = 3;		// o가 k+2개인 수열의 길이

	cin >> N;

	while (1) {
		len = len * 2 + temp;
		if (N <= len) break;
		temp++;
	}

	while (1) {
		long long prev = (len - temp) / 2; // 이전 문자열의 길이

		// N이 앞쪽 S(k=1) 수열 안에 있다면
		if (N <= prev) {
			len = prev;
			temp--;
		}
		// N이 o가 k+2개인 수열 안에 있다면
		else if (prev < N && N <= prev + temp) {
			if (N - prev == 1) cout << 'm';
			else cout << 'o';
			break;
		}
		// N이 뒤쪽 S(k-1) 수열 안에 있다면
		else if (prev + temp < N) {
			N -= prev + temp;
			len = prev;
			temp--;
		}
	}

	return 0;
}