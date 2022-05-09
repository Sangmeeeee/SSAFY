#include <string>
#include <iostream>
using namespace std;

string solve(string v) {
	// 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환한다.
	if (v == "") return "";

	// 2. 문자열을 두 "균형잡힌 괄호 문자열" u, v로 분리한다.
	// 2-1. u에 더 이상 분리할 수 없는 균형잡힌 괄호 문자열을 넣는다.
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

	// 2-2. v에서 u에 포함되는 부분들을 지운다.
	v.erase(0, left + right);

	// 3. 문자열 u가 올바른 괄호 문자열인지 검사한다.
	int flag = 0;
	for (int i = 0; i < u.length(); i++) {
		if (u[i] == '(') flag++;
		else {
			flag--;
			if (flag < 0) break;
		}
	}

	// 3-1. 수행한 결과 문자열을 u에 이어 붙인 후 반환한다.
	if (flag == 0) return u + solve(v);
	else {
		// 4. u가 올바른 문자열이 아니라면
		// 4-1 ~ 4-3.
		v = "(" + solve(v) + ")";
		// 4-4. u에 대한 처리
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