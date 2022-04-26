#include <iostream>
#include <vector>

using namespace std;

typedef struct edge {
	int u, v;
};

int N, M;
int parent[201];
int height[201];
vector<edge> graph;

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

	if (u == v)
		return;

	if (height[u] > height[v])
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

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		height[i] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int conn;
			cin >> conn;
			if (conn == 1)
				graph.push_back({ i, j });
		}
	}

	int m = 0;
	for (edge e : graph) {
		if (Find(e.u, e.u) == Find(e.v, e.v))
			continue;
		Union(e.u, e.v);
		if (++m == N - 1)
			break;
	}

	int m1, m2;
	cin >> m1;
	for (int i = 1; i < M; i++) {
		cin >> m2;
		if (Find(m1, m1) != Find(m2, m2)) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
	return 0;
}