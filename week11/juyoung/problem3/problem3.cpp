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
		// 특별한 도시 여부 저장
		if (s == 1) special[i] = true;
	}

	// 인접 행렬 생성
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			int sy = location[i].first;
			int sx = location[i].second;
			int ey = location[j].first;
			int ex = location[j].second;

			// 도시 간 이동 시간은 |r1 - r2| + |c1 - c2|
			adjMatrix[i][j] = abs(sy - ey) + abs(sx - ex);
			// 만약 두 도시가 특별한 도시라면
			// 기존 이동 시간과 텔레포트 시간 중 더 작은 값을 저장
			if (special[i] && special[j]) {
				adjMatrix[i][j] = min(adjMatrix[i][j], T);
			}
		}
	}

	// 플로이드 와샬 알고리즘으로 인접 행렬 반복적으로 갱신
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (adjMatrix[i][j] > adjMatrix[i][k] + adjMatrix[k][j])
					adjMatrix[i][j] = adjMatrix[i][k] + adjMatrix[k][j];
			}
		}
	}

	// 두 도시 A, B 입력 받고 해당하는 최소 이동 시간 출력
	cin >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << adjMatrix[A-1][B-1] << "\n";
	}

	return 0;
}