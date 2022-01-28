#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string str) {
	stack<int> s;

	for (int i = 0; i < str.length(); i++) {
		// ), }, ]인 경우
		// 아래의 두 경우가 올바른 문자열이 아니다.
		// 1. 스택이 비었는데 닫힌 괄호가 들어갈 때
		// 2. 스택의 top()이 해당 괄호의 짝이 아닐 때
		// 위 두 가지에 해당하지 않는다면 스택을 pop
		if (str[i] == ')') {
			if (s.empty()) return false;
			if (s.top() != '(') return false;
			s.pop();
			continue;
		}
		if (str[i] == '}') {
			if (s.empty()) return false;
			if (s.top() != '{') return false;
			s.pop();
			continue;
		}
		if (str[i] == ']') {
			if (s.empty()) return false;
			if (s.top() != '[') return false;
			s.pop();
			continue;
		}
		// (, {, [ 이면 push
		s.push(str[i]);
	}

	if (!s.empty())
		return false;
	return true;
}

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.size(); i++) {
		if (check(s)) answer++;
		int n = s[0];
		s.erase(0, 1);
		s.push_back(n);
	}
	return answer;
}

int main() {
	string str;
	cin >> str;
	cout << solution(str);
	return 0;
}