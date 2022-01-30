#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int N, K;
	vector<int> v, dist;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int pos;
		cin >> pos;
		v.push_back(pos);
	}
	sort(v.begin(), v.end());

	for (int i = 0; i < N - 1; i++)
		dist.push_back(v[i + 1] - v[i]);
	sort(dist.begin(), dist.end());

	int sum = 0;
	for (int i = 0; i < (int)dist.size() - (K - 1); i++)
		sum += dist[i];

	cout << sum;

	return 0;
}