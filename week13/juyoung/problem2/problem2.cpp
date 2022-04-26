#include <iostream>
using namespace std;

int G, P, g;
int root[100001];
int answer;

int find(int x) {
	if (x == root[x])
		return x;
	return root[x] = find(root[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	root[x] = y;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> G >> P;
	for (int i = 1; i <= G; i++) root[i] = i;
	for (int i = 0; i < P; i++) {
		cin >> g;
		// 더이상 도킹할 수 없는 경우
		if (find(g) == 0) break;
		Union(find(g), find(g) - 1);
		answer++;
	}

	cout << answer;
	return 0;
}