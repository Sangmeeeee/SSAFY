#include <iostream>
#include <string>
#include <limits.h>

using namespace std;

class City {
public:
	int s, x, y;
	City(){ }
	City(int s, int x, int y) {
		this->s = s;
		this->x = x;
		this->y = y;
	}
};

int N, M, T;
int dist[1001][1001];
City city[1001];

void floyd() {
	for (int k = 1; k <= N; k++)
		for (int i = 1; i <= N; i++)
			for (int j = 1; j <= N; j++)
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		int s, x, y;
		cin >> s >> x >> y;
		city[i] = City(s, x, y);
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			dist[i][j] = abs(city[i].x - city[j].x) + abs(city[i].y - city[j].y);
			// 직접적인 거리보다 텔레포트가 더 빠르면 time[i][j] 갱신
			if (city[i].s == 1 && city[j].s == 1)
				dist[i][j] = min(dist[i][j], T);
		}
	}

	floyd();

	cin >> M;
	string c;
	for (int i = 0; i < M; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		// cout << dist[c1][c2] << '\n';
		c += to_string(dist[c1][c2]);
		c += '\n';
	}

	cout << c;

	return 0;
}