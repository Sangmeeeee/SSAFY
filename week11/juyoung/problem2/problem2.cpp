#include <iostream>
#include <algorithm>
#define INF 9999
using namespace std;

int n, m, r;
int items[101];
int map[101][101];
int answer = 0;

int main() {
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++)
		cin >> items[i];
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		map[a][b] = l;
		map[b][a] = l;
	}

	// 연결되지 않은 곳의 거리는 충분히 큰 수로 초기화
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j && map[i][j] == 0)
				map[i][j] = INF;
		}
	}

	// 플로이드 와샬
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (map[i][j] > map[i][k] + map[k][j])
					map[i][j] = map[i][k] + map[k][j];
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		int item_cnt = 0;
		// 시작 지역의 아이템 개수 더하기
		item_cnt += items[i];
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			// 해당 지역이 수색 범위 내라면 그 지역의 아이템 개수 더하기
			if (map[i][j] <= m) item_cnt += items[j];
		}
		answer = max(answer, item_cnt);
	}

	cout << answer;
	return 0;
}