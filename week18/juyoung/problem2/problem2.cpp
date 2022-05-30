#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string change(int notation, int num) {
	string str = "";

	if (num == 0)
		return "0";

	while (num > 0) {
		char temp = (num % notation) + '0';
		// temp가 10~15면 대문자 A~F로 치환한다.
		if (temp > '9') {
			temp = 'A' + (num % notation - 10);
		}
		str += temp;
		num /= notation;
	}

	reverse(str.begin(), str.end());
	return str;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	string number = "";

	int num = 0;

	while(answer.length() < t) {
		// 현재 숫자 num을 n진법으로 바꾸고 number 문자열에 추가
		number += change(n, num);

		// 만약 튜브의 차례라면 answer에 해당 숫자 추가
		if (m == p) {
			if ((num + 1) % m == 0) 
				answer += number[num];
		}
		else if ((num + 1) % m == p) answer += number[num];
		num++;
	}

	return answer;
}

int main() {
	int n, t, m, p;
	string answer;

	cin >> n >> t >> m >> p;
	answer = solution(n, t, m, p);
	cout << answer;

	return 0;
}

/*
2 4 2 1
16 16 2 1
16 16 2 2
*/