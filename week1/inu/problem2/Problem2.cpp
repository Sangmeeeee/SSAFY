#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[100][100];
int R = 3, C = 3;

void check(bool line, int i, int range, int& max_size) {
	int cnt[101] = { 0, };
	vector<pair<int, int>> v;

	if (line == true) {
		for (int j = 0; j < range; j++)
			if (A[i][j] != 0)
				cnt[A[i][j]]++;
	}
	else {
		for (int j = 0; j < range; j++)
			if (A[j][i] != 0)
				cnt[A[j][i]]++;
	}

	for (int k = 1; k <= 100; k++)
		if (cnt[k] != 0)
			v.push_back({ cnt[k], k });
	sort(v.begin(), v.end());

	int idx = 0;
	int q_size = v.size() * 2 >= 100 ? 100 : v.size() * 2;
	if (line == true) {
		for (int j = 0; j < q_size; j += 2) {
			A[i][j] = v[idx].second;
			A[i][j + 1] = v[idx++].first;
		}

		for (int j = q_size; j < range; j++)
			A[i][j] = 0;
	}
	else {
		for (int j = 0; j < q_size; j += 2) {
			A[j][i] = v[idx].second;
			A[j + 1][i] = v[idx++].first;
		}

		for (int j = q_size; j < range; j++)
			A[j][i] = 0;
	}

	max_size = q_size > max_size ? q_size : max_size;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int r, c, k;
	int time = 0;

	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];

	for (int t = 0; t <= 100; ++t) {
		if (A[r - 1][c - 1] == k) {
			cout << t;
			return 0;
		}

		int max_size = 0;

		if (R >= C) {
			for (int i = 0; i < R; i++)
				check(true, i, C, max_size);
			C = max_size;
		}
		else {
			for (int i = 0; i < C; i++)
				check(false, i, R, max_size);
			R = max_size;
		}
	}

	cout << -1;
}