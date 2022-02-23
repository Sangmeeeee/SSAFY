#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ans = 0;
int N, L, R, X;
vector<int> level;
bool selected[15];

void selectProblems(int idx, int n) {
	if (idx == N) {
		if (n >= 2) {
			vector<int> list;
			int sum = 0;
			for (int i = 0; i < N; i++)
				if (selected[i]) {
					sum += level[i];
					list.push_back(level[i]);
				}
			
			if (sum >= L && sum <= R) {
				sort(list.begin(), list.end());
				if (list[(int)list.size() - 1] - list[0] >= X)
					ans++;
			}
		}
		return;
	}

	selected[idx] = true;
	selectProblems(idx + 1, n + 1);
	selected[idx] = false;
	selectProblems(idx + 1, n);
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);

	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		level.push_back(n);
	}

	selectProblems(0, 0);
	cout << ans;
	return 0;
}