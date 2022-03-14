#include <iostream>
#include <vector>

using namespace std;

char ans;
vector<int> S(1, 3);

void findChar(int N, int K) {
	if (K == 0) {
		if (N == 1)
			ans = 'm';
		else
			ans = 'o';
		return;
	}

	if (N > S[K - 1] && N <= S[K] - S[K - 1]) {
		if (N == S[K - 1] + 1)
			ans = 'm';
		else
			ans = 'o';
		return;
	}

	N -= S[K - 1] + (K + 3);
	for (int k = 0; k <= K - 1; k++) {
		if (N <= S[k]) {
			findChar(N, k);
			break;
		}
	}			
}

int main() {
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	
	int N;
	cin >> N;

	for (int K = 1; K <= 27; K++) {
		int l = (K + 3) + (2 * S[K - 1]);
		S.push_back(l);

		if (N <= S[K]) {
			findChar(N, K);
			break;
		}
	}

	cout << ans;

	return 0;
}