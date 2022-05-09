#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct pos {
	int x, y;
};

int M, N;
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
bool visited[100][100];

int bfs(int i, int j, vector<vector<int>> picture) {
	queue<pos> q;
	int color = picture[i][j];
	int area_size = 1;

	q.push({ i, j });
	visited[i][j] = true;

	while (!q.empty()) {
		pos p = q.front();
		q.pop();

		for (int d = 0; d < 4; d++) {
			int x = p.x + dx[d];
			int y = p.y + dy[d];

			if (x < 0 || x >= M || y < 0 || y >= N)
				continue;

			if (picture[x][y] == color && !visited[x][y]) {
				visited[x][y] = true;
				q.push({ x, y });
				area_size++;
			}
		}
	}

	return area_size;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	vector<int> answer(2);
	int number_of_area = 0;
	int max_size_of_one_area = 0;

	M = m;
	N = n;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			if (picture[i][j] && !visited[i][j]) {
				int area_size = bfs(i, j, picture);
				number_of_area++;
				max_size_of_one_area =
					area_size > max_size_of_one_area ?
					area_size : max_size_of_one_area;
			}

	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m = 13;
	int n = 16;
	vector<vector<int>> picture = {
{0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
{0, 1, 1, 1, 1, 2, 1, 1, 1, 1, 2, 1, 1, 1, 1, 0},
{0, 1, 1, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1, 1, 1, 0},
{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
{0, 1, 3, 3, 3, 1, 1, 1, 1, 1, 1, 3, 3, 3, 1, 0},
{0, 1, 1, 1, 1, 1, 2, 1, 1, 2, 1, 1, 1, 1, 1, 0},
{0, 0, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 0, 0},
{0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
{0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	};
	vector<int> result = solution(m, n, picture);
	cout << result[0] << ' ' << result[1];
}

/*
{
		{1, 1, 1, 0},
		{1, 2, 2, 0},
		{1, 0, 0, 1},
		{0, 0, 0, 1},
		{0, 0, 0, 3},
		{0, 0, 0, 3}
	};
*/