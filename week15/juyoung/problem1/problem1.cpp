#include <iostream>
#include <string>
using namespace std;

int solution(string s) {
	int answer = s.length(); // �ϳ��� ������� ���� ���̷� �ʱ�ȭ
	int len = 1;			 // �ڸ� ������ ����

	// �ڸ� �� �ִ� ������ ������ �ִ� s.length()/2���̴�.
	// ex. ababcdcdababcdcd => 2ababcbcb
	// len�� s.length()�� ���ݺ��� �������� �����Ѵ�.
	while (len <= s.length()/2) {
		string temp;	// ������ ���� ���ڿ�
		string ans_str;	// ������ ���ڿ��� �����ϴ� ����
		int cnt = 1;	// ������ �� �ִ� ����

		// 1. ó������ len��ŭ �߶󳽴�.
		temp = s.substr(0, len);

		// 2. ���ڿ� s�� Ž���Ѵ�.
		for (int i = len; i < s.length(); i+=len) {
			if (temp == s.substr(i, len)) {
				// 2-1. temp�� ���� �ε���(i)���� len��ŭ �߶� ���ڿ��� ���ٸ�
				// ������ �� �ִ� ������ �þ��.
				cnt++;
			}
			else {
				// 2-2-1. �ƴ϶�� temp�� ���� ������ temp�� ans_str�� ���� ���·� ���δ�.
				if (cnt > 1) ans_str += to_string(cnt);
				ans_str += temp;

				// 2-2-2. ���� ��ġ���� �ٽ� len��ŭ �ڸ� ���ڿ��� temp�� �����Ͽ�
				// �������ʹ� �̸� �������� ���ڿ��� �����ϵ��� �Ѵ�.
				temp = s.substr(i, len);
				cnt = 1;
			}
		}

		// 3. for���� ���ٺ��� ������ temp�� ans_str�� �������� ���� ä�� ����ȴ�.
		// ���� ans_str�� temp�� ��ġ�� �۾��� �ʿ��ϴ�.
		// �̶� cnt�� 1���� ū �����̸� cnt ���� temp�� �Բ� ans_str�� ���� ���·� ���ľ� �Ѵ�.
		if (cnt > 1) ans_str += to_string(cnt);
		ans_str += temp;

		// 4. ���� answer���� ans_str�� ���̰� �۴ٸ�, ans_str�� ���̸� answer�� �����Ѵ�.
		// answer���� ������� ������ ���ڿ� �� ���� ���̰� ª�� ���ڿ��� ���̰� ����Ǿ� �ִ�.
		if (answer > ans_str.length())
			answer = ans_str.length();

		// 5. len�� 1��ŭ �÷� while���� �ݺ��Ѵ�.
		len++;
	}

	return answer;
}

int main() {
	string s;
	cin >> s;

	cout << solution(s);

	return 0;
}