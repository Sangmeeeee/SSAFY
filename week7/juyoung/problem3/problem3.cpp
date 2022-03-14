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
	// 이미 어떤 구역이 채울 수 없다고 판단됐다면
	if (!check) return;
	// 채우려는 구역의 어느 모서리가 0과 같아진다면
	if (l <= 0 || w <= 0 || h <= 0) return;
	for (int i = N-1; i >= 0; i--) {
		int c = cube[i].first;
		
		// 만약 해당 종류의 큐브를 다 썼다면
		if (cube[i].second <= 0) continue;
		// 만약 해당 종류의 큐브가 박스보다 크다면
		if (c > l || c > w || c > h) continue;

		// 해당 큐브 1개를 넣고 큐브 개수를 1만큼 감소
		answer++;
		cube[i].second--;

		// 남은 3개의 구역 재귀적으로 채우기
		func(l-c, c, c);
		func(l, c, h-c);
		func(l, w-c, h);
		
		// 1개 채우고 나면 바로 return
		return;
	}

	// for문 안에서 조건문을 계속 continue 하다가 for문이 종료되는 경우
	// 즉, 전부 채울 수 없는 경우
	check = false;
}

int main() {
	cin >> length >> width >> height;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		// 큐브의 종류와 개수를 pair로 관리
		cube.push_back({ pow(2, a), b });
	}

	func(length, width, height);

	if (check) cout << answer;
	else cout << -1;

	return 0;
}