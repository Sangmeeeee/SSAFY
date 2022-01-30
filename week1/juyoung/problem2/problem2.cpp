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
	if (i.second == j.second) // ����Ƚ���� ������ Ŀ���� ������ ����
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
		// time�� 100�� �Ѿ�� -1 ��� �� ����
		if (time > 100) {
			cout << -1;
			return 0;
		}

		if (max_r_size >= max_c_size) {
			int range = 0;
			// R ����
			for (int i = 0; i < max_r_size; i++) {
				// cnt �迭�� pair ���·� {���� ����, �ش� ������ ���� Ƚ��} ����
				for (int j = 0; j < max_c_size; j++) {
					if (A[i][j] == 0) continue;
					int curr = cnt[A[i][j]].second;
					cnt[A[i][j]] = make_pair(A[i][j], curr + 1);
				}

				// 1����-���� Ƚ��, 2����-ũ��� �������� ����
				sort(cnt.begin(), cnt.end(), compare);

				// temp ���Ϳ� ���ĵ� cnt �迭�� �� push
				vector<int> temp;
				for (int j = 100; j >= 1; j--) {
					if (cnt[j].first == 0) break;
					temp.push_back(cnt[j].second);
					temp.push_back(cnt[j].first);
				}
				reverse(temp.begin(), temp.end());

				// ���� ������� ���Ͱ� ���� �ִ� ���� ���̺��� ��ٸ� ������Ʈ
				range = max(range, (int)temp.size());

				// ���ο� ������ ������Ʈ
				int j, k;
				for (j = 0; j < temp.size(); j++) A[i][j] = temp[j];
				for (k = j; k < max_c_size; k++) A[i][k] = 0;

				// cnt �ʱ�ȭ
				cnt.assign(101, { 0, 0 });
			}

			max_c_size = range;
		}
		else {
			// C ����
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

				// ���� ������� ���Ͱ� ���� �ִ� ���� ���̺��� ��ٸ� ������Ʈ
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