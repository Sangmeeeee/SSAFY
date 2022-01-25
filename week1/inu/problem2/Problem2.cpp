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
	
	// 100���� �ݺ�
	for (int t = 0; t <= 100; ++t) {
		// ������ �ð� ����ϰ� ����
		if (A[r - 1][c - 1] == k) {
			cout << t;
			return 0;
		}

		int q_size;
		int max_size = 0;
		vector<pair<int, int>> v;

		// �� ���� >= �� ����
		if (R >= C) {
			for (int i = 0; i < R; i++) {
				int idx = 0;
				int cnt[101] = { 0, };

				// ���� Ƚ�� ī��Ʈ
				// ���� �迭���� ���� ū ���� ã�� max_num�� ����
				for (int j = 0; j < C; j++)
					if (A[i][j] != 0) {
						cnt[A[i][j]]++;
						max_num = A[i][j] > max_num ? A[i][j] : max_num;
					}

				// max_num������ cnt�迭 ��ȸ
				// {���� Ƚ��, ����}�� ���Ϳ� �ְ� ����
				for (int k = 1; k <= max_num; k++)
					if (cnt[k] != 0)
						v.push_back({ cnt[k], k });
				sort(v.begin(), v.end(), compare);

				// ���� ũ�� * 2�� 100�� ���� �ʵ��� ����
				q_size = v.size() * 2 >= 100 ? 100 : v.size() * 2;

				for (int j = 0; j < q_size; j += 2) {
					A[i][j] = v[idx].second;
					A[i][j + 1] = v[idx++].first;
				}

				// q_size�� �Ѿ�� �κ��� 0���� �ٲ���
				for (int j = q_size; j < C; j++)
					A[i][j] = 0;

				// ���� ���Ŀ��� ���� ū ���� ������ ���س��� ���� ������ �ٲ���
				max_size = q_size > max_size ? q_size : max_size;

				v.clear();
			}
			C = max_size;
		}
		// �� ���� < �� ����
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