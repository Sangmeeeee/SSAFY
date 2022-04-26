#include <iostream>
#include <vector>

using namespace std;

int N, M, T;
int parent[51];
int height[51];
int ans = 0;
int tRoot;

void swap(int& u, int& v) {
	int temp = u;
	u = v;
	v = temp;
}

int Find(int origin, int u) {
	if (parent[u] == u) {
		parent[origin] = u;
		return u;
	}
	return Find(origin, parent[u]);
}

void Union(int u, int v) {
	u = Find(u, u);
	v = Find(v, v);

	// �� �� �ϳ��� tRoot�̰ų� ���̰� ������ ���� �ٲٱ�
	if (u == tRoot || (v != tRoot && height[u] > height[v]))
		swap(u, v);

	parent[u] = v;

	if (height[u] == height[v])
		height[v]++;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> M;
	cin >> T;

	// �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		height[i] = 1;
	}

	// tRoot: ������ �˰� �ִ� ����� ������ ��Ʈ
	int b;
	if (T > 0) {		
		cin >> tRoot;
		for (int t = 1; t < T; t++) {
			cin >> b;
			parent[b] = tRoot;
		}
		if (T > 1)
			height[tRoot] = 2;
	}	

	// �� ��Ƽ�� ���鼭 union-find
	vector<vector<int>> party(M);
	for (int m = 0; m < M; m++) {
		int n, p1, p2;
		cin >> n >> p1;
		party[m].push_back(p1);
		
		for (int i = 1; i < n; i++) {
			cin >> p2;
			party[m].push_back(p2);
			if (Find(p1, p1) != Find(p2, p2))
				Union(p1, p2);
		}
	}

	// �� ��Ƽ �������� �θ� tRoot�� �ƴϸ� ���� ����
	for (int m = 0; m < M; m++) {
		bool flag = false;
		for (auto i : party[m]) {
			if (Find(i, i) == tRoot) {
				flag = true;
				break;
			}
		}
		if (!flag)
			ans++;
	}		

	cout << ans;

	return 0;
}