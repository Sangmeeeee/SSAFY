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
			// '0'�� ��� (01 �˻�)
			if (s[idx] == '0') {
				idx++;
				// ���� ���ڰ� '1'�� �ƴ� �� => ����X
				if (idx >= s.length() || s[idx] == '0')
					isPattern = false;
				idx++;
			}
			else {
				// '1'�� ��� (100+1+ �˻�)
				int zero_cnt = 0;
				idx++;
				while (idx < s.length() && s[idx] == '0') {
					zero_cnt++;
					idx++;
				}
				// '0'�� 2�� �̻� �������� ���� �� => ����X
				if (zero_cnt < 2 || idx >= s.length())
					isPattern = false;

				int one_cnt = 0;
				while (idx < s.length() && s[idx] == '1') {
					one_cnt++;
					idx++;
				}
				// '1'�� 2�� �̻� ���� �� '00'�� ���� �� => 100+1+ ���� ��˻�
				if (one_cnt > 1 && idx + 1 < s.length() && s.substr(idx, 2) == "00")
					idx--;
			}
		}

		if (isPattern) cout << "YES" << "\n";
		else           cout << "NO" << "\n";
	}
}