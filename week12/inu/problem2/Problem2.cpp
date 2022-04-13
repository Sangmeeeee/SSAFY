#include <iostream>
#include <vector>
#define INF 2000000000

using namespace std;
typedef long long ll;

class edge {
public:
	int u, v, w;
	edge() {}
	edge(int u, int v, int w) {
		this->u = u;
		this->v = v;
		this->w = w;
	}
};

int TC, N, M, W;

vector<ll> bellmanFord(vector<edge> graph, int src) {
	vector<long long> upper(N + 1, INF);
	bool success;
	upper[src] = 0;
	
	for (int i = 0; i < N; i++) {
		success = false;
		for (auto e : graph) {
			if (upper[e.u] == INF) continue;
			if (upper[e.v] > upper[e.u] + e.w) {
				upper[e.v] = upper[e.u] + e.w;
				success = true;
			}
		}
		if (!success) break;
	}

	if (success) upper.clear();
	return upper;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> TC;
	for (int t = 1; t <= TC; t++) {
		int S, E, T;
		bool isPossible = false;
		vector<edge> graph;
		
		cin >> N >> M >> W;
		// 도로
		for (int i = 0; i < M; i++) {
			cin >> S >> E >> T;
			graph.push_back(edge(S, E, T));
			if (S != E)
				graph.push_back(edge(E, S, T));
		}
		// 웜홀
		for (int i = 0; i < W; i++) {
			cin >> S >> E >> T;
			graph.push_back(edge(S, E, -T));
		}
		// 각 정점을 시작점으로 했을 때 음수 사이클 유무
		for (int i = 1; i <= N; i++) {
			vector<ll> dist = bellmanFord(graph, i);
			if (dist.empty()) {
				isPossible = true;
				break;
			}
		}
		if (isPossible)
			cout << "YES" << "\n";
		else
			cout << "NO" << "\n";
	}
}