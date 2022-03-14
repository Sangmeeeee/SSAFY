#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int length, width, height;
int N;
vector<pair<int, int>> cube;
bool check = true;
int answer = 0;

void func(int l, int w, int h) {
	// �̹� � ������ ä�� �� ���ٰ� �Ǵܵƴٸ�
	if (!check) return;
	// ä����� ������ ��� �𼭸��� 0�� �������ٸ�
	if (l <= 0 || w <= 0 || h <= 0) return;
	for (int i = N-1; i >= 0; i--) {
		int c = cube[i].first;
		
		// ���� �ش� ������ ť�긦 �� ��ٸ�
		if (cube[i].second <= 0) continue;
		// ���� �ش� ������ ť�갡 �ڽ����� ũ�ٸ�
		if (c > l || c > w || c > h) continue;

		// �ش� ť�� 1���� �ְ� ť�� ������ 1��ŭ ����
		answer++;
		cube[i].second--;

		// ���� 3���� ���� ��������� ä���
		func(l-c, c, c);
		func(l, c, h-c);
		func(l, w-c, h);
		
		// 1�� ä��� ���� �ٷ� return
		return;
	}

	// for�� �ȿ��� ���ǹ��� ��� continue �ϴٰ� for���� ����Ǵ� ���
	// ��, ���� ä�� �� ���� ���
	check = false;
}

int main() {
	cin >> length >> width >> height;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		// ť���� ������ ������ pair�� ����
		cube.push_back({ pow(2, a), b });
	}

	func(length, width, height);

	if (check) cout << answer;
	else cout << -1;

	return 0;
}