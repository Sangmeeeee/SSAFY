#include <string>
#include <vector>
#include <queue>
#include <iostream>
#define SIZE 5
using namespace std;

int bfs(vector<vector<string>> places, int idx, int y, int x) {
	queue<pair<int, int>> q;
	bool visited[SIZE][SIZE];
	int dy[4] = { -1, 1, 0, 0 };
	int dx[4] = { 0, 0, -1, 1 };
	int cnt = 2;

	// �湮 ���� �ʱ�ȭ
	for (int i = 0; i < SIZE; i++)
		for (int j = 0; j < SIZE; j++)
			visited[i][j] = false;

	q.push({ y, x });
	visited[y][x] = true;

	// 2�� �ݺ�
	while (cnt--) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= SIZE || nx < 0 || nx >= SIZE) continue;
			if (visited[ny][nx]) continue;
			if (places[idx][ny][nx] == 'X') continue;
			if (places[idx][ny][nx] == 'P') return 0;

			q.push({ ny, nx });
			visited[ny][nx] = true;
		}
	}

	return 1;
}

vector<int> solution(vector<vector<string>> places) {
	vector<int> answer;

	for (int i = 0; i < SIZE; i++) {
		// �����ڰ� �ɾ��ִ� �ڸ��� ��ġ���� ���Ϳ� �����Ѵ�.
		vector<pair<int, int>> loc;
		for (int j = 0; j < SIZE; j++) {
			for (int k = 0; k < SIZE; k++) {
				if (places[i][j][k] == 'P')
					loc.push_back({ j, k });
			}
		}

		// �������� �ڸ��� �ϳ��� ������ ����ư�� �Ÿ��� 2 �̳��� ������ �˻��Ѵ�.
		bool isGood = true;
		for (int p = 0; p < (int)loc.size(); p++) {
			int result = bfs(places, i, loc[p].first, loc[p].second);
			if (result == 0) {
				isGood = false;
				break;
			}
		}

		if (isGood) answer.push_back(1);
		else answer.push_back(0);
	}

	return answer;
}

int main() {
	vector<vector<string>> places;
	vector<int> answer;

	for (int i = 0; i < SIZE; i++) {
		vector<string> temp;
		for (int j = 0; j < SIZE; j++) {
			string str;
			cin >> str;
			temp.push_back(str);
		}
		places.push_back(temp);
	}

	answer = solution(places);
	for (int i = 0; i < (int)answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}

/*
POOOP
OXXOX
OPXPX
OOXOX
POXXP
POOPX
OXPXP
PXXXO
OXXXO
OOOPP
PXOPX
OXOXP
OXPOX
OXXOP
PXPOX
OOOXX
XOOOX
OOOXX
OXOOX
OOOOO
PXPXP
XPXPX
PXPXP
XPXPX
PXPXP
*/