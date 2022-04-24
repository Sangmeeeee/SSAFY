#include <iostream>
using namespace std;

int N, M;
int n, m;
int root[201];
int plan[1001];
bool isAvailable = true;

int find(int x) {
	if (root[x] == x)
		return x;
	return root[x] = find(root[x]);
}

void Union(int x, int y) {
	x = find(x);
	y = find(y);

	// �� ���� ���� ��Ʈ ���� ����
	if (x < y) root[y] = x;
	else root[x] = y;
}

int main() {
	cin >> N >> M;

	for (int i = 0; i <= N; i++) root[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> n;
			// ����Ǿ��ٸ� ��ġ��
			if (n == 1)
				Union(i, j);
		}
	}

	for (int i = 0; i < M; i++)	cin >> plan[i];

	// ù��° ����� ��Ʈ ��������
	int r = root[plan[0]];
	// ���� ��Ʈ�� r�� �ٸ��ٸ� ������� �ʾҴٴ� �ǹ��̹Ƿ� �Ұ���
	for (int i = 1; i < M; i++)
		if (r != root[plan[i]]) isAvailable = false;

	if (isAvailable) cout << "YES";
	else cout << "NO";
}

/*
3
2
0 1 0
1 0 1
0 1 0
1 1

����: YES


4
4
0 0 0 1
0 0 1 0
0 1 0 1
1 0 1 0
3 1 2 4

����: YES


5
2
0 1 1 0 0
1 0 0 0 0
1 0 0 0 0
0 0 0 0 1
0 0 0 1 0
1 5

����: NO
*/