#include <iostream>
#include <vector>
#include <tuple>
#define INF 1e9 * 2 // 20��
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

	// ��� ��忡 ���� �ִ� �Ÿ��� INF�� �ʱ�ȭ
	for (int i = 1; i <= N; i++)
		dist[i] = INF;

	// �������� 0���� �ʱ�ȭ
	dist[1] = 0;

	for (int i = 1; i <= N - 1; i++) {
		for (int j = 0; j < edge.size(); j++) {
			int from = get<0>(edge[j]);
			int to = get<1>(edge[j]);
			int cost = get<2>(edge[j]);

			// �ѹ��̶� ���� �����̶�� ������ �Ÿ� �� �� ������Ʈ
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
		// ������Ʈ �Ǵ� ������ �ִٸ� ���� ����Ŭ�� ����
		// ��, �ð��� ������ ���� ������ �ǵ��� �� �����Ƿ� -1 ���
		if (dist[to] > dist[from] + cost) {
			cout << -1;
			return 0;
		}
	}

	for (int i = 2; i <= N; i++) {
		// �ش� ���÷� ���� ��ΰ� ���ٸ� -1 ���
		if (dist[i] == INF)
			cout << -1 << "\n";
		else
			cout << dist[i] << "\n";
	}

	return 0;
}