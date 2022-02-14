#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int height1[500001], height2[500001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, H, c;
	cin >> N >> H;
	for (int i = 0; i < N; i++) {
		cin >> c;
		if (i % 2 == 0) height1[c]++; // 석순
		else height2[c]++;			  // 종유석
	}
	
	for (int i = H; i > 1; i--) {
		height1[i - 1] += height1[i];
		height2[i - 1] += height2[i];
	}
		
	for (int i = H; i > 1; i--)
		height1[i] += height2[H - i + 1];

	sort(height1, height1 + (H + 1));

	int cnt = 1;
	for (int i = 2; i <= H; i++) {
		if (height1[1] == height1[i])
			cnt++;
	}

	cout << height1[1] << ' ' << cnt;

	return 0;
}