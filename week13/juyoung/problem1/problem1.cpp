#include <iostream>
using namespace std;

int N, M;
int truthCnt;	// ������ �ƴ� ����� ��
int truth[51];	// ������ �ƴ� ����� �����ϴ� �迭
int root[51];
int party[51][51];
int answer;

int find(int x) {
	if (root[x] == x)
		return x;
	return root[x] = find(root[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);
	root[y] = x;
}

int main() {
	cin >> N >> M >> truthCnt;

	// root �迭 �ʱ�ȭ
	for (int i = 1; i <= N; i++) root[i] = i;

	// ������ �ƴ� ��� �� ��Ƽ ���� �Է�
	for (int i = 0; i < truthCnt; i++)
		cin >> truth[i];
	for (int i = 0; i < M; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> party[i][j];
			// ��Ƽ�� �����ϴ� ù��° ����� �����Ѵ�.
			Union(party[i][0], party[i][j]);
		}
	}

	answer = M;
	// ��� ��Ƽ�� ���� ������ �ƴ� ����� �ִ��� �˻��Ѵ�.
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < truthCnt; j++) {
			// ��Ƽ�� �����ϴ� ù��° ����� ������ �ƴ� ����� ��Ʈ�� ���ٸ�
			// �� ����� ������ �ƴ� ����̹Ƿ� �ش� ��Ƽ������ ����� ������ ���� �� ����.
			if (find(party[i][0]) == find(truth[j])) {
				answer--;
				break;
			}
		}
	}

	cout << answer;
	return 0;
}