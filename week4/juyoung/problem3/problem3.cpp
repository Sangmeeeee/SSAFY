#include <iostream>
#include <algorithm>
using namespace std;

int N, M, L;
int rest[52];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M >> L;

	rest[0] = 0;
	for (int i = 1; i <= N; i++)
		cin >> rest[i];
	rest[N+1] = L;

	sort(rest, rest + N + 1); // Á¤·Ä

	int low = 1, high = L;
	int answer = 0;
	while (low <= high) {
		int mid = (low + high) / 2;

		int cnt = 0;
		for (int i = 0; i <= N; i++) {
			int dist = rest[i + 1] - rest[i];
			cnt += dist / mid;
			if (dist%mid == 0)
				cnt--;
		}
		if (cnt > M) {
			low = mid + 1;
		}
		else {
			high = mid - 1;
			answer = mid;
		}
	}

	cout << answer;

	return 0;
}