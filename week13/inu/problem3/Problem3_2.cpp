#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef struct edge {
	int w, u, v;
}edge;

struct compare {
	bool operator()(edge& e1, edge& e2) {
		return e1.w < e2.w;
	}
};

int N, M, S, E;
int parent[100001];
int height[100001];
priority_queue<edge, vector<edge>, compare> pq;

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
	cin >> S >> E;

	for (int i = 1; i <= N; i++) {
		parent[i] = i;
		height[i] = 1;
	}

	for (int i = 0; i < M; i++) {
		int h1, h2, w;
		cin >> h1 >> h2 >> w;
		pq.push({ w, h1, h2 });
	}

	while (!pq.empty()) {
		edge e = pq.top();
		pq.pop();
		// �̹� ����Ǿ� ������ �н�
		if (Find(e.u, e.u) == Find(e.v, e.v))
			continue;
		// �ƴϸ� ����
		Union(e.u, e.v);
		// ������ �߰��ؼ� �������� �������� ����Ǿ��� ��
		if (Find(S, S) == Find(E, E)) {
			cout << e.w;
			return 0;
		}
	}
	cout << 0;
	return 0;
}