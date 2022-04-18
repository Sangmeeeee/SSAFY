#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#define INF 1e9
using namespace std;

int n, m;
int u, v, w;
vector<tuple<int, int, int>> road;	// 입력 받은 골목길 정보 저장
int dist[101];		// 최단 거리 저장
int parent[101];	// 이전에 방문한 노드 저장
bool visited[101];	// 도착지와 연결된 노드들을 표시
bool cycle;			// 도착지까지 가는 데 음수 사이클의 여부
vector<int> path;	// parent 배열에 저장된 값들을 통해 경로를 저장

void bfs(int node) {
	queue<int> q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < (int)road.size(); i++) {
			int start = get<0>(road[i]);
			int end = get<1>(road[i]);

			// 인접 리스트 형태가 아니라 간선 전부를 road 벡터에 저장했으므로
			// 큐에서 꺼낸 노드와 for문에서 참조하고 있는 도로의 출발 노드가 같은지
			// 검사하는 과정이 필요하다.
			// 또한 현재 도로의 도착 노드를 방문하지 않았을 때에만
			// visited 배열을 갱신하고 큐에 현재 도로의 도착 노드를 삽입한다.
			if (curr == start && !visited[end]) {
				visited[end] = true;
				q.push(end);
			}
		}
	}
}

void bellmanford() {
	// n-1번 이후 한 번 더 돌려서 음수 사이클 여부 검사
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < (int)road.size(); j++) {
			int from = get<0>(road[j]);
			int to = get<1>(road[j]);
			int cost = get<2>(road[j]);

			if (dist[from] == INF) continue;
			if (dist[to] > dist[from] + cost) {
				// n번째 돌렸을 때, 즉 i=n일 때 값 변화가 있고
				// 도착지와 연결된 노드라면(=bfs 이후 visited[n]이 true라면)
				// 도착지로 가는 경로에 음수 사이클이 존재하는 것이다.
				if (i == n) {
					// from과 연결된 노드들을 visited 배열에 표시
					bfs(from);
					if (visited[n]) {
						cycle = true;
						return;
					}
				}

				dist[to] = dist[from] + cost;
				parent[to] = from; // 부모 노드 저장
			}
		}
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> u >> v >> w;
		road.push_back({ u,v,-w });
	}

	// 벨만포드로 최단 거리 및 음수 사이클 여부 구하기
	for (int i = 2; i <= n; i++) dist[i] = INF;
	bellmanford();

	// 1. 출발지에서 도착지로 가는 경로가 아예 없거나
	// 2. 도착지로 가는 경로에 음수 사이클이 존재하면 종료
	if (dist[n] == INF || cycle)
		cout << -1;
	// 3. 사이클이 존재하지 않으면 경로 출력
	else if (!cycle) {
		int node = n;
		path.push_back(node);
		// 저장해둔 부모 노드를 거슬러 올라가며 경로 저장
		while (parent[node] > 0) {
			path.push_back(parent[node]);
			node = parent[node];
		}

		for (int i = (int)path.size() - 1; i >= 0; i--)
			cout << path[i] << " ";
	}

	return 0;
}

/*
5 7
1 2 3
1 3 4
3 1 -7
2 3 2
3 4 1
4 2 -5
4 5 1

답: 1 2 3 4 5


5 7
1 2 3
1 3 4
3 1 -7
2 3 2
3 4 1
4 2 -2
4 5 1

답: -1


5 7
1 2 1
2 3 1
3 4 1
4 5 1
1 5 10
1 2 50
2 5 80

답: 1 2 5


5 5
1 2 -1
2 3 1
3 4 1
4 2 1
2 5 -1

답: -1


4 4
1 4 3
2 3 1
3 2 1
4 2 1

답 : 1 4


4 4
1 2 1
2 3 1
3 4 1
4 1 1

답 : -1


4 5
1 2 1
2 3 1
3 4 1
3 2 1
4 1 1

답 : -1


4 5
1 2 1
2 3 1
3 4 1
3 1 1
4 1 1

답 : -1
*/