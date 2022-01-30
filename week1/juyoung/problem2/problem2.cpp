#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int r, c, k;
int time = 0;
int max_r_size = 3, max_c_size = 3;
int A[102][102];
vector<pair<int, int>> cnt(101);

bool compare(pair<int, int> i, pair<int, int> j) {
	if (i.second == j.second) // 등장횟수가 같으면 커지는 순으로 정렬
		return i.first < j.first;
	return i.second < j.second;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> r >> c >> k;
	r -= 1;
	c -= 1;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> A[i][j];
		}
	}

	while (A[r][c] != k) {
		// time이 100을 넘어가면 -1 출력 후 종료
		if (time > 100) {
			cout << -1;
			return 0;
		}

		if (max_r_size >= max_c_size) {
			int range = 0;
			// R 연산
			for (int i = 0; i < max_r_size; i++) {
				// cnt 배열에 pair 형태로 {기존 숫자, 해당 숫자의 등장 횟수} 저장
				for (int j = 0; j < max_c_size; j++) {
					if (A[i][j] == 0) continue;
					int curr = cnt[A[i][j]].second;
					cnt[A[i][j]] = make_pair(A[i][j], curr + 1);
				}

				// 1순위-등장 횟수, 2순위-크기로 오름차순 정렬
				sort(cnt.begin(), cnt.end(), compare);

				// temp 벡터에 정렬된 cnt 배열의 값 push
				vector<int> temp;
				for (int j = 100; j >= 1; j--) {
					if (cnt[j].first == 0) break;
					temp.push_back(cnt[j].second);
					temp.push_back(cnt[j].first);
				}
				reverse(temp.begin(), temp.end());

				// 만약 만들어진 벡터가 현재 최대 열의 길이보다 길다면 업데이트
				range = max(range, (int)temp.size());

				// 새로운 행으로 업데이트
				int j, k;
				for (j = 0; j < temp.size(); j++) A[i][j] = temp[j];
				for (k = j; k < max_c_size; k++) A[i][k] = 0;

				// cnt 초기화
				cnt.assign(101, { 0, 0 });
			}

			max_c_size = range;
		}
		else {
			// C 연산
			int range = 0;
			for (int i = 0; i < max_c_size; i++) {
				for (int j = 0; j < max_r_size; j++) {
					if (A[j][i] == 0) continue;
					int curr = cnt[A[j][i]].second;
					cnt[A[j][i]] = make_pair(A[j][i], curr + 1);
				}

				sort(cnt.begin(), cnt.end(), compare);

				vector<int> temp;
				for (int j = 100; j >= 1; j--) {
					if (cnt[j].first == 0) break;
					temp.push_back(cnt[j].second);
					temp.push_back(cnt[j].first);
				}
				reverse(temp.begin(), temp.end());

				// 만약 만들어진 벡터가 현재 최대 행의 길이보다 길다면 업데이트
				range = max(range, (int)temp.size());

				int j, k;
				for (j = 0; j < temp.size(); j++) A[j][i] = temp[j];
				for (k = j; k < max_r_size; k++) A[k][i] = 0;

				cnt.assign(101, { 0, 0 });
			}

			max_r_size = range;
		}

		time++;
	}

	cout << time;

	return 0;
}