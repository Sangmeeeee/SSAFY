#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N, M;
	vector<int> seq;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		seq.push_back(input);
	}
	
	sort(seq.begin(), seq.end());

	int min_value = 2000000000;
	for (int i = N - 1; i > 0; i--) {
		for (int j = i - 1; j >= 0; j--) {
			if (seq[i] - seq[j] >= M) {
				min_value = min(min_value, seq[i] - seq[j]);
				break;
			}
		}
		if (min_value == M)
			break;
	}
	
	cout << min_value;

	return 0;
}