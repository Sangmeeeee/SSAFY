#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int N, H;
	int bottom[100000];
	int top[100000];
	cin >> N >> H;

	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		if (i % 2 == 0) { // ���� �Է�
			bottom[i / 2] = input;
		}
		else { // ������ �Է�
			top[i / 2] = input;
		}
	}

	sort(bottom, bottom + N/2);
	sort(top, top + N/2);

	int minimum = 999999999;
	int count = 0;
	// 1�� �������� ���ʴ�� ������ �������� ���� ���ϱ�
	for (int h = 1; h <= H; h++) {
		int c = 0;
		
		// ����
		int idx = lower_bound(bottom, bottom + N / 2, h) - bottom;
		c += N / 2 - idx;

		// ������
		idx = upper_bound(top, top + N / 2, H - h) - top;
		c += N / 2 - idx;

		if (c < minimum) {
			minimum = c;
			count = 1;
		}
		else if(c == minimum)
			count++;
	}

	cout << minimum << " " << count;
}