#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string origin, str;
	vector<char> v;

	cin >> origin >> str;
	int len = str.length();

	for (int i = 0; i < origin.length(); i++) {
		v.push_back(origin[i]);
		
		if (v.size() >= len) {
			int cnt = 0;

			for (int j = 0; j < len; j++) {
				if (v[v.size() - len + j] == str[j])
					cnt++;
				else
					break;
			}

			if (cnt == len) {
				for (int j = 0; j < len; j++)
					v.pop_back();
			}
		}
	}

	if (v.size() > 0) {
		for (int i = 0; i < v.size(); i++)
			cout << v[i];
	}
	else
		cout << "FRULA";

	return 0;
}