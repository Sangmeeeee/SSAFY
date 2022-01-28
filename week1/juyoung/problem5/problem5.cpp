#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool check(string str) {
	stack<int> s;

	for (int i = 0; i < str.length(); i++) {
		// ), }, ]�� ���
		// �Ʒ��� �� ��찡 �ùٸ� ���ڿ��� �ƴϴ�.
		// 1. ������ ����µ� ���� ��ȣ�� �� ��
		// 2. ������ top()�� �ش� ��ȣ�� ¦�� �ƴ� ��
		// �� �� ������ �ش����� �ʴ´ٸ� ������ pop
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
		// (, {, [ �̸� push
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