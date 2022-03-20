#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, M;
	int ans = INT_MAX;
	vector<int> arr;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		arr.push_back(n);
	}
	sort(arr.begin(), arr.end());

	int i = 0, j = 1;
	while (j < N && i <= j) {
		if (i == j) {
			j++;
			continue;
		}
		
		int sub = abs(arr[i] - arr[j]);
		if (sub >= M) {
			ans = min(sub, ans);
			if (sub == M)
				break;
			else
				i++;
		}
		else
			j++;
	}

	cout << ans;

	return 0;
}