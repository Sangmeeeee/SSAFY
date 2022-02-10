#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector<string> table;
int cnt = 0;
int R, C;

bool check(int start, int end) {
	set<string> s;

	for (int i = 0; i < C; i++) {
		string temp;
		for (int j = start; j < end; j++)
			temp += table[j][i];
		
		if (s.find(temp) != s.end())
			return true;

		s.insert(temp);
	}

	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		table.push_back(s);
	}

	int left = 1, right = R;
	int mid;

	while (left <= right) {
		mid = (left + right) / 2;

		// 중복이 있을 때
		if (check(mid, R)) {
			right = mid - 1;
		}
		// 중복이 없을 때
		else {
			cnt = mid;
			left = mid + 1;
		}
	}

	cout << cnt;

	return 0;
}