#include <iostream>

using namespace std;

int gate[100001];
int G, P;
int ans = 0;

void swap(int& u, int& v) {
	int temp = u;
	u = v;
	v = temp;
}

int Find(int origin, int u) {
	if (gate[u] == u) {
		gate[origin] = u;
		return gate[u];
	}
	return Find(origin, gate[u]);
}

void Union(int u, int v) {
	u = Find(u, u);
	v = Find(v, v);
	gate[u] = v;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> G >> P;

	for (int i = 1; i <= G; i++)
		gate[i] = i;
	// 게이트 수보다 비행기가 더 많을 때
	for (int i = G + 1; i <= P; i++)
		gate[i] = G;

	for (int i = 0; i < P; i++) {
		int u, v;
		cin >> u;
		v = gate[u];
		v = Find(v, v);

		if (v == 0)
			break;
		
		Union(v, v - 1);
		ans++;
	}

	cout << ans;

	return 0;
}