#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct edge {
	int u, v, w;
}edge;

bool compare(edge e1, edge e2) {
	return e1.w > e2.w;
}

int N, M;
int parent[100001];
int height[100001];
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

	for (int i = 0; i < M; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		graph.push_back({ u, v, w });
	}
	sort(graph.begin(), graph.end(), compare);

	int u, v;
	cin >> u >> v;
	for (edge e : graph) {
		if (Find(e.u, e.u) == Find(e.v, e.v))
			continue;
		Union(e.u, e.v);
		if (Find(u, u) == Find(v, v)) {
			cout << e.w;
			break;
		}
	}
	return 0;
}