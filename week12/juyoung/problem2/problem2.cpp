#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#define INF 1e9*2 // 20억
using namespace std;

int TC;
int N, M, W;
int dist[501];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> TC;

	for (int t = 0; t < TC; t++) {
		cin >> N >> M >> W;
		vector<tuple<int, int, int>> edge(N + 1);
		memset(dist, INF, N + 1);

		// 도로 입력 (양방향)
		for (int i = 0; i < M; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			edge.push_back({ S,E,T });
			edge.push_back({ E,S,T });
		}
		// 웜홀 입력 (단방향)
		for (int i = 0; i < W; i++) {
			int S, E, T;
			cin >> S >> E >> T;
			edge.push_back({ S,E,-T });
		}

		// 벨만포드
		dist[1] = 0;
		for (int i = 1; i <= N - 1; i++) {
			for (int j = 0; j < (int)edge.size(); j++) {
				int from = get<0>(edge[j]);
				int to = get<1>(edge[j]);
				int cost = get<2>(edge[j]);

				// 한 번이라도 계산된 정점일 때 거리 비교 및 갱신
				if (dist[from] == INF) continue;
				if (dist[to] > dist[from] + cost) {
					dist[to] = dist[from] + cost;
				}
			}
		}
		
		bool isPossible = false;
		for (int i = 0; i < edge.size(); i++) {
			int from = get<0>(edge[i]);
			int to = get<1>(edge[i]);
			int cost = get<2>(edge[i]);

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) {
				isPossible = true;
				break;
			}
		}

		if (isPossible) cout << "YES\n";
		else cout << "NO\n";
	}
}