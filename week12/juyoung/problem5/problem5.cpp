#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define INF 1e9
using namespace std;

int N, A, B, M;
int S, E, P;
vector<tuple<int, int, int>> edge;
long dist[51];
int money[51];
bool cycle;
bool visited[51];

void bfs(int node) {
	queue<int> q;
	visited[node] = true;
	q.push(node);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < (int)edge.size(); i++) {
			int from = get<0>(edge[i]);
			int to = get<1>(edge[i]);

			// 현재 노드와 간선의 출발 지점이 같고
			// 간선의 도착 지점이 아직 방문하지 않은 곳이라면
			if (curr == from && !visited[to]) {
				visited[to] = true;
				q.push(to);
			}
		}
	}
}

void bellmanford() {
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < (int)edge.size(); j++) {
			int from = get<0>(edge[j]);
			int to = get<1>(edge[j]);
			int cost = get<2>(edge[j]);

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost - money[to]) {
				if (i == N) {
					// 사이클에 포함되는 노드와 연결된 노드들을 visited 배열에 저장
					bfs(from);
					// 만약 도착 노드가 사이클에 포함되는 노드와 연결되어 있다면
					// 도착 노드에 도착했을 때 돈을 무한히 많이 가질 수 있게 됨
					if (visited[B]) {
						cycle = true;
						return;
					}
				}

				dist[to] = dist[from] + cost - money[to];
			}
		}
	}
}

int main() {
	cin >> N >> A >> B >> M;
	for (int i = 0; i < M; i++) {
		cin >> S >> E >> P;
		edge.push_back({ S,E,P });
	}
	for (int i = 0; i < N; i++)
		cin >> money[i];

	// dist 배열을 무한대로 초기화, 시작 지점만 벌 수 있는 돈으로 초기화
	for (int i = 0; i < 51; i++)
		dist[i] = INF;
	dist[A] = -money[A];

	// 벨만포드
	bellmanford();

	if (dist[B] == INF) cout << "gg";
	else if (cycle) cout << "Gee";
	else cout << -dist[B];

	return 0;
}

/*
4 0 3 4
0 1 0
1 2 0
2 1 0
0 3 10
10 10 10 10

답: 10


4 0 3 4
0 1 1
1 2 1
2 0 1
0 3 1
2 2 2 0

답: Gee


3 0 2 4
0 1 9999
1 2 9999
1 1 9999
0 2 0
10000 10000 10000
답: Gee

*/