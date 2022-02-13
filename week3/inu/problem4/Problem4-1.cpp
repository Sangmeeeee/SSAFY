#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	int R, C;
	vector<string> v(1000, "");
	cin >> R >> C;
	
	for(int i = 0; i < R; i++)
		for (int j = 0; j < C; j++) {
			char c;
			cin >> c;
			v[j].push_back(c);
		}
	
	int cnt = 0;
	bool f = true;
	for (int i = 1; i < R; i++) {
		set<string> s;

		for (int j = 0; j < C; j++) {
			string temp = v[j].substr(i);
			if (s.find(temp) != s.end()) {
				f = false;
				break;
			}				
			s.insert(temp);
		}

		if (!f) break;
		cnt++;
	}

	cout << cnt;

	return 0;
}