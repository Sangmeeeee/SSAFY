#include <iostream>
#include <vector>
#include <tuple>
#define INF 1e9 * 2 // 20억
using namespace std;

int N, M;
long long dist[501];
vector<tuple<int, int, int>> edge;
bool isCycle;

int main() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		edge.push_back({ A,B,C });
	}

	// 모든 노드에 대한 최단 거리를 INF로 초기화
	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	// 시작점을 0으로 초기화
	dist[1] = 0;

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int from = get<0>(edge[j]);
			int to = get<1>(edge[j]);
			int cost = get<2>(edge[j]);

			// 한번이라도 계산된 정점이라면 정점의 거리 비교 및 업데이트
			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost)
				dist[to] = dist[from] + cost;
		}
	}

	for (int i = 0; i < edge.size(); i++) {
		int from = get<0>(edge[i]);
		int to = get<1>(edge[i]);
		int cost = get<2>(edge[i]);

		if (dist[from] == INF) continue;
		// 업데이트 되는 정점이 있다면 음수 사이클이 존재
		// 즉, 시간을 무한히 오래 전으로 되돌릴 수 있으므로 -1 출력
		if (dist[to] > dist[from] + cost) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i <= N; i++) {
		// 해당 도시로 가는 경로가 없다면 -1 출력
		if (dist[i] == INF)
			cout << -1 << "\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}