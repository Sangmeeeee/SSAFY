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
		// ���� ������ �࿡�� �ߺ��Ǵ� ���� üũ
		if (++alphabet[str[R - 1][i] - 97] > 1) {
			isDuplicated = true;
			break;
		}
	}

	// ������ �࿡ �ߺ��Ǵ� ���ڰ� �����ٸ� ��� ���� ������ �ߺ��Ǵ� ���ڿ��� ���ٴ� ��
	if (!isDuplicated) {
		cout << R - 1;
		return 0;
	}

	string temp[1000];
	set<string> s;
	for (int i = R - 1; i >= 0; i--) {
		// ������ ����� ���� �ö󰡸� �κй��ڿ� �����ؼ� set�� insert
		for (int j = 0; j < C; j++) {
			temp[j] += str[i][j];
			s.insert(temp[j]);
		}
		// ���� set�� ũ�Ⱑ ���� ������ ���ٸ� �ߺ��� ���ٴ� ��
		if (s.size() == C) {
			cout << i;
			return 0;
		}
		s.clear();
	}

	return 0;
}