#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

vector<pair<int, int>> adjList[51];
int dist[51];

void dijkstra(int start) {
	// ������ ����ϸ� �տ������� �ּڰ��� ã�� ������ ���������� Ž���ؾ� �ϹǷ�
	// pq�� ����ؼ� ������ ��� �� �Ÿ��� �� ���� �� ���� �湮�� �� �ֵ��� ��
	priority_queue<pair<int, int>> pq;

	// ���� ���������� ���� ���� �ִ� �ð��� 0
	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty()) {
		int d = -pq.top().first;
		int node = pq.top().second;
		pq.pop();

		// ������ �������� ���� �ּ� �ð� ���
		for (int i = 0; i < adjList[node].size(); i++) {
			int next = adjList[node][i].first;
			int cost = adjList[node][i].second;

			// ���� ������������ �ּ� �ð� + ���� ������������ �Ÿ�
			int new_cost = d + cost;

			// ���� ����� �ּ� �ð����� �۴ٸ� ������Ʈ
			if (new_cost < dist[next]) {
				dist[next] = new_cost;
				pq.push({ -new_cost, next });
			}
		}
	}
}

int solution(int N, vector<vector<int> > road, int K) {
	int answer = 0;

	for (int i = 0; i < (int)road.size(); i++) {
		int from = road[i][0];
		int to = road[i][1];
		int time = road[i][2];

		adjList[from].push_back({ to, time });
		adjList[to].push_back({ from, time });
	}

	// �ִ� �ð� �迭 �ʱ�ȭ
	fill(dist, dist + N + 1, INF);

	// 1�� ���������� ���
	dijkstra(1);

	for (int i = 1; i <= N; i++) {
		if (dist[i] <= K)
			answer++;
	}

	cout << answer;

	return answer;
}

int main() {
	int N;
	vector<vector<int>> road;
	int K;

	cin >> N;
	while (1) {
		int a, b, c;
		vector<int> temp;
		cin >> a >> b >> c;
		if (a == 0 && b == 0 && c == 0)
			break;

		temp.push_back(a);
		temp.push_back(b);
		temp.push_back(c);

		road.push_back(temp);
	}
	cin >> K;
	solution(N, road, K);
}

/*
5
1 2 1
2 3 3
5 2 2
1 4 2
5 3 1
5 4 2
0 0 0
3
*/

/*
6
1 2 1
1 3 2
2 3 2
3 4 3
3 5 2
3 5 3
5 6 2
0 0 0
4
*/