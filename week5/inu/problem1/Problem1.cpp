#include <iostream>
#include <string>

using namespace std;

int N;
int cnt = -1;

void find(string s, char end, int len) {
	if (s.size() == len) {
		cnt++;
		if (cnt == N) {
			cout << s;
			exit(0);
		}
		return;
	}	

	for (char c = '0'; c <= end; c++) {
		s += c;
		find(s, c - 1, len);
		s.pop_back();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> N;

	for (int len = 1; len <= 10; len++)
		for (char end = '0'; end <= '9'; end++) {
			string s;
			s.push_back(end);
			find(s, end - 1, len);
		}

	cout << "-1";

	return 0;
}