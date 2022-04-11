#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int N, T, M;
vector<pair<int, int>> location;
bool special[1001];
int adjMatrix[1001][1001];

int main() {
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		int s, y, x;
		cin >> s >> y >> x;
		location.push_back({ y, x });
		// Ư���� ���� ���� ����
		if (s == 1) special[i] = true;
	}

	// ���� ��� ����
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			int sy = location[i].first;
			int sx = location[i].second;
			int ey = location[j].first;
			int ex = location[j].second;

			// ���� �� �̵� �ð��� |r1 - r2| + |c1 - c2|
			adjMatrix[i][j] = abs(sy - ey) + abs(sx - ex);
			// ���� �� ���ð� Ư���� ���ö��
			// ���� �̵� �ð��� �ڷ���Ʈ �ð� �� �� ���� ���� ����
			if (special[i] && special[j]) {
				adjMatrix[i][j] = min(adjMatrix[i][j], T);
			}
		}
	}

	// �÷��̵� �ͼ� �˰������� ���� ��� �ݺ������� ����
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
					adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
			}
		}
	}

	// �� ���� A, B �Է� �ް� �ش��ϴ� �ּ� �̵� �ð� ���
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << adjMatrix[A-1][B-1] << "\n";
	}

	return 0;
}