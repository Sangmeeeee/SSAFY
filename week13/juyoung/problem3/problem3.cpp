#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M;
int s, e;
vector<tuple<int, int, int>> edge;
vector<int> root;
vector<vector<pair<int, int>>> adjList;
vector<bool> visited;
vector<int> dist;
int answer = 1e9;

int find(int x) {
	if (root[x] == x)
		return x;
	return root[x] = find(root[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	// 더 작은 값을 기준으로 부모 노드를 갱신한다.
	if (x < y) root[y] = x;
	else root[x] = y;
}

bool dfs(int node, int cnt) {
	// 도착 지점에 도착하면
	if (node == e) {
		// s에서 e로 가는 경로 상의 간선 중 무게 제한의 최솟값을 찾는다.
		for (int i = 0; i < cnt; i++)
			answer = min(answer, dist[i]);
		return true;
	}

	for (int i = 0; i < (int)adjList[node].size(); i++) {
		int next = adjList[node][i].first;
		int cost = adjList[node][i].second;

		if (visited[next]) continue;
		visited[next] = true;
		dist[cnt] = cost;
		// 만약 도착지점에 도착했다면 연쇄적으로 true를 return 한다.
		if (dfs(next, cnt + 1)) return true;
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	cin >> s >> e;

	// 루트 노드를 초기화한다.
	for (int i = 0; i <= N; i++) root.push_back(i);

	for (int i = 0; i < M; i++) {
		int h1, h2, k;
		cin >> h1 >> h2 >> k;
		// 최대값을 구해야하므로 비용을 음수로 입력 받는다.
		edge.push_back({ -k, h1, h2 });
	}

	// 1. Kruskal 알고리즘 수행
	// 간선을 정렬한다.
	sort(edge.begin(), edge.end());

	// 간선을 연결한다.
	adjList.resize(N + 1);
	for (int i = 0; i < edge.size(); i++) {
		int k = -get<0>(edge[i]); // 무게 제한
		int x = get<1>(edge[i]); // 출발 정점
		int y = get<2>(edge[i]); // 도착 정점

		// x와 y를 연결했을 때 사이클이 생긴다면 연결하지 않고 패스한다.
		if (find(x) == find(y)) continue;
		// 사이클이 생기지 않는다면 연결한다.
		Union(x, y);
		// DFS를 위한 새로운 인접리스트를 생성한다.
		adjList[x].push_back({ y, k });
		adjList[y].push_back({ x, k });
	}

	// 2. DFS 수행
	for (int i = 0; i <= N; i++) {
		visited.push_back(false);
		dist.push_back(-1);
	}
	visited[s] = true;
	dfs(s, 0);

	// s에서 e까지 갈 수 없다면 0 출력
	// 아니라면 정답 출력
	if (answer == 1e9) cout << 0;
	else cout << answer;

	return 0;
}