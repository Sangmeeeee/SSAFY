#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N;
	vector<int> solution;
	pair<int, int> ans = { 1000000000, 1000000000 };

	cin >> N;
	for (int i = 0; i < N; i++) {
		int s;
		cin >> s;
		solution.push_back(s);
	}

	sort(solution.begin(), solution.end());

	int i = 0, j = (int)solution.size() - 1;
	while (i < j) {
		int sum = solution[i] + solution[j];

		if (abs(sum) < abs(ans.first + ans.second)) {
			ans = { solution[i], solution[j] };
			if (sum == 0) {
				break;
			}
		}

		if (abs(solution[i]) < abs(solution[j]))
			j--;
		else
			i++;
	}

	cout << ans.first << ' ' << ans.second;

	return 0;
}