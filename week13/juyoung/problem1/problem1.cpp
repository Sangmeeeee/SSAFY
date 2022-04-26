#include <iostream>
using namespace std;

int N, M;
int truthCnt;	// 진실을 아는 사람의 수
int truth[51];	// 진실을 아는 사람을 저장하는 배열
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

	// root 배열 초기화
	for (int i = 1; i <= N; i++) root[i] = i;

	// 진실을 아는 사람 및 파티 정보 입력
	for (int i = 0; i < truthCnt; i++)
		cin >> truth[i];
	for (int i = 0; i < M; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			cin >> party[i][j];
			// 파티에 참여하는 첫번째 사람과 연결한다.
			Union(party[i][0], party[i][j]);
		}
	}

	answer = M;
	// 모든 파티에 대해 진실을 아는 사람이 있는지 검사한다.
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < truthCnt; j++) {
			// 파티에 참여하는 첫번째 사람과 진실을 아는 사람의 루트가 같다면
			// 그 사람은 진실을 아는 사람이므로 해당 파티에서는 과장된 내용을 말할 수 없다.
			if (find(party[i][0]) == find(truth[j])) {
				answer--;
				break;
			}
		}
	}

	cout << answer;
	return 0;
}