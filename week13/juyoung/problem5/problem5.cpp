#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

int N, M;
int A, B, C;
int S, E;
vector<int> root;
vector<tuple<int, int, int>> edge;
vector<vector<pair<int, int>>> adjList;
vector<bool> visited;
vector<int> dist;
int answer = 1e9*2;

int find(int x) {
	if (x == root[x])
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

bool dfs(int node, int depth) {
	// 만약 공장이 위치한 다른 섬에 도착했다면
	if (node == E) {
		// 중량 제한 중 최솟값을 찾는다.
		for (int i = 0; i < depth; i++)
			answer = min(answer, dist[i]);
		return true;
	}

	// 인접리스트를 탐색한다.
	for (int i = 0; i < (int)adjList[node].size(); i++) {
		int next = adjList[node][i].first;
		int cost = adjList[node][i].second;
		
		if (visited[next]) continue;
		visited[next] = true;
		dist[depth] = cost;
		// 만약 도착지에 도착하여 정답을 찾았다면 연쇄적으로 true를 리턴한다.
		if (dfs(next, depth + 1)) return true;
	}

	return false;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i <= N; i++) root.push_back(i);
	for (int i = 0; i < M; i++) {
		cin >> A >> B >> C;
		// 오름차순 정렬을 위해 중량 제한은 음수로 저장한다.
		edge.push_back({ -C,A,B });
	}
	cin >> S >> E;

	// 1. Kruskal 알고리즘 수행
	// Kruskal 알고리즘을 수행하여 연결된 간선의 수를 줄인다.
	sort(edge.begin(), edge.end());

	adjList.resize(N + 1);
	for (int i = 0; i < M; i++) {
		int c = -get<0>(edge[i]);
		int a = get<1>(edge[i]);
		int b = get<2>(edge[i]);

		// 두 섬을 연결했을 때 사이클이 생긴다면 패스한다.
		if (find(a) == find(b)) continue;
		Union(a, b);
		// DFS를 위한 인접리스트를 생성한다.
		adjList[a].push_back({ b, c });
		adjList[b].push_back({ a, c });
	}

	// 2. DFS 수행
	for (int i = 0; i <= N; i++) {
		visited.push_back(false);
		dist.push_back(-1);
	}
	visited[S] = true;
	dfs(S, 0);

	// 만약 공장이 위치한 두 섬이 서로 도달할 수 없다면 0을 출력하고
	// 그렇지 않다면 answer를 출력한다.
	if (answer == 1e9*2) cout << 0;
	else cout << answer;

	return 0;
}

/*
10000 3
9998 9999 2
10000 9998 3
9999 10000 2
9998 10000

정답: 3


5 5
1 2 5
2 3 4
1 3 3
1 4 3
4 5 1
5 1

정답: 1


6 9
1 2 7
1 3 8
1 4 7
1 6 9
2 3 7
3 4 7
3 5 7
4 5 7
4 6 7
6 3

정답: 8


6 12
1 2 7
1 3 8
1 4 7
1 6 9
2 3 7
3 4 7
3 5 7
4 5 7
4 6 7
3 6 7
1 3 11
5 6 12
6 3

정답: 9


3 1
1 2 999999999
1 2

정답: 999999999

3 3
1 2 2
3 1 2
2 3 2
1 3

정답: 2

3 3
1 2 2
3 1 2
2 3 99999999
1 3

정답:2


9 9
1 4 11
1 5 2
4 5 4
4 3 10
4 2 7
5 2 10
5 6 13
3 2 9
2 6 8
1 6

정답: 9
*/