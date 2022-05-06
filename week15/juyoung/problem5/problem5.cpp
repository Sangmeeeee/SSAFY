#include <string>
#include <iostream>
using namespace std;

string solve(string v) {
	// 1. �Է��� �� ���ڿ��� ���, �� ���ڿ��� ��ȯ�Ѵ�.
	if (v == "") return "";

	// 2. ���ڿ��� �� "�������� ��ȣ ���ڿ�" u, v�� �и��Ѵ�.
	// 2-1. u�� �� �̻� �и��� �� ���� �������� ��ȣ ���ڿ��� �ִ´�.
	string u;
	int left = 0, right = 0;
	for (int i = 0; i < v.length(); i++) {
		if (v[i] == '(') {
			left++;
			u += '(';
		}
		else {
			right++;
			u += ')';
		}
		if (left == right) break;
	}

	// 2-2. v���� u�� ���ԵǴ� �κе��� �����.
	v.erase(0, left + right);

	// 3. ���ڿ� u�� �ùٸ� ��ȣ ���ڿ����� �˻��Ѵ�.
	int flag = 0;
	for (int i = 0; i < u.length(); i++) {
		if (u[i] == '(') flag++;
		else {
			flag--;
			if (flag < 0) break;
		}
	}

	// 3-1. ������ ��� ���ڿ��� u�� �̾� ���� �� ��ȯ�Ѵ�.
	if (flag == 0) return u + solve(v);
	else {
		// 4. u�� �ùٸ� ���ڿ��� �ƴ϶��
		// 4-1 ~ 4-3.
		v = "(" + solve(v) + ")";
		// 4-4. u�� ���� ó��
		u = u.substr(1, u.length() - 2);
		for (int i = 0; i < u.length(); i++) {
			if (u[i] == '(')
				u[i] = ')';
			else u[i] = '(';
		}

		return v + u;
	}
}

string solution(string p) {
	string answer = "";
	answer = solve(p);
	return answer;
}

int main() {
	string answer;
	string input;

	cin >> input;
	answer = solution(input);
	cout << answer;
	
	return 0;
}

/*
(()())()
result: (()())()

)(
result: ()

()))((()
result: ()(())()
*/