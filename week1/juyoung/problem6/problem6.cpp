#include <iostream>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int T;
	string s;

	cin >> T;
	while (T--) {
		cin >> s;
		bool isPattern = true;
		int idx = 0;

		while (isPattern && idx < s.length()) {
			// '0'인 경우 (01 검사)
			if (s[idx] == '0') {
				idx++;
				// 다음 문자가 '1'이 아닐 때 => 패턴X
				if (idx >= s.length() || s[idx] == '0')
					isPattern = false;
				idx++;
			}
			else {
				// '1'인 경우 (100+1+ 검사)
				int zero_cnt = 0;
				idx++;
				while (idx < s.length() && s[idx] == '0') {
					zero_cnt++;
					idx++;
				}
				// '0'이 2개 이상 존재하지 않을 때 => 패턴X
				if (zero_cnt < 2 || idx >= s.length())
					isPattern = false;

				int one_cnt = 0;
				while (idx < s.length() && s[idx] == '1') {
					one_cnt++;
					idx++;
				}
				// '1'이 2개 이상 나온 후 '00'이 나올 때 => 100+1+ 패턴 재검사
				if (one_cnt > 1 && idx + 1 < s.length() && s.substr(idx, 2) == "00")
					idx--;
			}
		}

		if (isPattern) cout << "YES" << "\n";
		else           cout << "NO" << "\n";
	}
}