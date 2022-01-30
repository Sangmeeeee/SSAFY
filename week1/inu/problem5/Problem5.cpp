#include <iostream>
#include <stack>
using namespace std;

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < (int)s.length(); i++) {
		bool flag = true;
		stack<char> st;

		for (int j = i; s[j] != NULL; j++) {
			if (s[j] == '{' || s[j] == '[' || s[j] == '(') {
				st.push(s[j]);
				continue;
			}
			
			if (st.empty()) {
				flag = false;
				break;
			}

			if (st.top() == '{' && s[j] == '}' ||
				st.top() == '(' && s[j] == ')' ||
				st.top() == '[' && s[j] == ']')
				st.pop();
			else {
				flag = false;
				break;
			}
		}

		if (flag) {
			for (int j = 0; j < i; j++) {
				if (s[j] == '{' || s[j] == '[' || s[j] == '(') {
					st.push(s[j]);
					continue;
				}

				if (st.empty()) {
					flag = false;
					break;
				}

				if (st.top() == '{' && s[j] == '}' ||
					st.top() == '(' && s[j] == ')' ||
					st.top() == '[' && s[j] == ']')
					st.pop();
				else {
					flag = false;
					break;
				}
			}
		}

		if (flag)
			answer++;
	}

	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	char str[1000];
	cin >> str;
	cout << solution(str);
}