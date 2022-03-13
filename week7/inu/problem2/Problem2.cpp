#include <iostream>
#include <map>

using namespace std;

int N, K;
int sum[200001];
long long cnt = 0;
map <int, long long> m; // <ºÎºÐÇÕ, °¹¼ö>

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> sum[i];
		sum[i] += sum[i - 1];
	}

	for (int i = 1; i <= N; i++) {
		if (sum[i] == K)
			cnt++;

		if (m[sum[i] - K] > 0)
			cnt += m[sum[i] - K];

		m[sum[i]]++;
	}

	cout << cnt;
}