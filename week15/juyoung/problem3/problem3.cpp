#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int number_of_area;
int max_size_of_one_area;
bool visited[101][101];

void bfs(int sy, int sx, int m, int n, vector<vector<int>> picture) {
	queue<pair<int, int>> q;
	int dy[] = { -1,1,0,0 };
	int dx[] = { 0,0,-1,1 };
	int color;
	int cnt = 1;

	q.push({ sy,sx });
	visited[sy][sx] = true;
	color = picture[sy][sx];

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= m || nx < 0 || nx >= n) continue;
			if (visited[ny][nx]) continue;
			if (picture[ny][nx] == color) {
				visited[ny][nx] = true;
				q.push({ ny, nx });
				cnt++;
			}
		}
	}

	if (max_size_of_one_area < cnt)
		max_size_of_one_area = cnt;
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	number_of_area = 0;
	int max_size_of_one_area = 0;
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
			visited[i][j] = false;

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (picture[i][j] == 0) continue;
			if (visited[i][j]) continue;
			bfs(i, j, m, n, picture);
			number_of_area++;
		}
	}

	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	int m, n;
	vector<vector<int>> picture;
	vector<int> answer;
	
	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		vector<int> temp;
		for (int j = 0; j < n; j++) {
			int input;
			cin >> input;
			temp.push_back(input);
		}
		picture.push_back(temp);
	}

	answer = solution(m, n, picture);
	cout << answer[0] << ", " << answer[1];

	return 0;
}

/*
6 4
1 1 1 0
1 2 2 0
1 0 0 1
0 0 0 1
0 0 0 3
0 0 0 3
*/