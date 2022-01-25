#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first < p2.first;
}

int A[100][100];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int R = 3, C = 3;
	int r, c, k;
	int time = 0;
	int max_num = 0;

	cin >> r >> c >> k;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			cin >> A[i][j];
	
	// 100번만 반복
	for (int t = 0; t <= 100; ++t) {
		// 맞으면 시간 출력하고 종료
		if (A[r - 1][c - 1] == k) {
			cout << t;
			return 0;
		}

		int q_size;
		int max_size = 0;
		vector<pair<int, int>> v;

		// 행 개수 >= 열 개수
		if (R >= C) {
			for (int i = 0; i < R; i++) {
				int idx = 0;
				int cnt[101] = { 0, };

				// 등장 횟수 카운트
				// 현재 배열에서 가장 큰 수를 찾아 max_num에 저장
				for (int j = 0; j < C; j++)
					if (A[i][j] != 0) {
						cnt[A[i][j]]++;
						max_num = A[i][j] > max_num ? A[i][j] : max_num;
					}

				// max_num까지만 cnt배열 조회
				// {등장 횟수, 숫자}로 벡터에 넣고 정렬
				for (int k = 1; k <= max_num; k++)
					if (cnt[k] != 0)
						v.push_back({ cnt[k], k });
				sort(v.begin(), v.end(), compare);

				// 벡터 크기 * 2가 100을 넘지 않도록 조정
				q_size = v.size() * 2 >= 100 ? 100 : v.size() * 2;

				for (int j = 0; j < q_size; j += 2) {
					A[i][j] = v[idx].second;
					A[i][j + 1] = v[idx++].first;
				}

				// q_size를 넘어가는 부분은 0으로 바꿔줌
				for (int j = q_size; j < C; j++)
					A[i][j] = 0;

				// 현재 정렬에서 가장 큰 열의 개수를 구해놓고 정렬 끝나고 바꿔줌
				max_size = q_size > max_size ? q_size : max_size;

				v.clear();
			}
			C = max_size;
		}
		// 행 개수 < 열 개수
		else {
			int max_cnt = 100;

			for (int i = 0; i < C; i++) {
				int idx = 0;
				int cnt[101] = { 0, };

				for (int j = 0; j < R; j++)
					if (A[j][i] != 0) {
						cnt[A[j][i]]++;
						max_num = A[j][i] > max_num ? A[j][i] : max_num;
					}

				for (int k = 1; k <= max_num; k++)
					if (cnt[k] != 0)
						v.push_back({ cnt[k], k });
				sort(v.begin(), v.end(), compare);

				q_size = v.size() * 2 >= 100 ? 100 : v.size() * 2;

				for (int j = 0; j < q_size; j += 2) {
					A[j][i] = v[idx].second;
					A[j + 1][i] = v[idx++].first;
				}

				for (int j = q_size; j < R; j++)
					A[j][i] = 0;

				max_size = q_size > max_size ? q_size : max_size;

				v.clear();
			}
			R = max_size;
		}
	}

	cout << -1;
}