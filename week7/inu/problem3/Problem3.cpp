#include <iostream>
#include <math.h>

using namespace std;

int length, width, height;
int N, max_i, ans = 0;
long long volume = 0;
pair<int, int> cube[20]; // cube[i]: <2^i, ����ü ����>

void fillBox(int l, int w, int h) {
	if (l <= 0 || w <= 0 || h <= 0)
		return;

	// ���� �� �ִ� ���� ū ������ü ã��
	int idx = -1, side = 0;
	for (int i = max_i; i >= 0; i--) {
		if (cube[i].second == 0)
			continue;

		side = cube[i].first;
		if (side <= l && side <= w && side <= h) {
			cube[i].second--;
			ans++;
			idx = i;
			break;
		}
	}
	
	// ���� �� �ִ� ������ü�� ������ ����
	if (idx == -1)
		return;

	// ������ü �ְ� ���� ���ǿ��� ����
	volume -= (long long)side*side*side;

	// ���� ���ǿ� ���ؼ� �ٽ� ä���
	fillBox(side, side, h - side);
	fillBox(l - side, side, h);
	fillBox(l, w - side, h);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> length >> width >> height;
	cin >> N;

	int A, B;
	for (int i = 0; i < N; i++) {		
		cin >> A >> B;
		cube[A] = { (int)pow(2, A), B };
	}
	max_i = A;

	volume = (long long)length * width * height;
	fillBox(length, width, height);

	if (volume != 0)
		cout << -1;
	else
		cout << ans;

	return 0;
}