#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(long long n) {
	if (n <= 1) return false;
	if (n == 2) return true;
	for (long long i = 3; i <= sqrt(n); i++) {
		if (n%i == 0) return false;
	}
	return true;
}

int solution(int n, int k) {
	int answer = 0;

	// n을 k진수로 바꾸기
	string number = "";
	char c = 0;
	while (n > 0) {
		c = n % k + '0';
		number += c;
		n /= k;
	}
	reverse(number.begin(), number.end());

	// number에서 10진수 소수 찾기
	string temp = "";
	for (int i = 0; i < number.length(); i++) {
		if (number[i] == '0') {
			if (temp != "" && isPrime(stoll(temp)))
				answer++;
			temp = "";
			continue;
		}
		temp += number[i];
	}

	if (temp != "")
		if (isPrime(stoll(temp)))
			answer++;

	return answer;
}

int main() {
	int n, k, answer;

	cin >> n >> k;
	answer = solution(n, k);
	cout << answer;

	return 0;
}