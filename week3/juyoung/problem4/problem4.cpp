#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
	int R, C;

	cin >> R >> C;
	string str[1000];

	for (int i = 0; i < R; i++)
		cin >> str[i];

	int alphabet[26] = { 0, };
	bool isDuplicated = false;
	for (int i = 0; i < C; i++) {
		// 가장 마지막 행에서 중복되는 글자 체크
		if (++alphabet[str[R - 1][i] - 97] > 1) {
			isDuplicated = true;
			break;
		}
	}

	// 마지막 행에 중복되는 글자가 없었다면 모든 행을 지워도 중복되는 문자열이 없다는 뜻
	if (!isDuplicated) {
		cout << R - 1;
		return 0;
	}

	string temp[1000];
	set<string> s;
	for (int i = R - 1; i >= 0; i--) {
		// 마지막 행부터 위로 올라가며 부분문자열 생성해서 set에 insert
		for (int j = 0; j < C; j++) {
			temp[j] += str[i][j];
			s.insert(temp[j]);
		}
		// 만약 set의 크기가 열의 개수와 같다면 중복이 없다는 뜻
		if (s.size() == C) {
			cout << i;
			return 0;
		}
		s.clear();
	}

	return 0;
}