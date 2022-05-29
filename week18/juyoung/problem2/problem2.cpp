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
		// temp�� 10~15�� �빮�� A~F�� ġȯ�Ѵ�.
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
		// ���� ���� num�� n�������� �ٲٰ� number ���ڿ��� �߰�
		number += change(n, num);

		// ���� Ʃ���� ���ʶ�� answer�� �ش� ���� �߰�
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