#include <string>
#include <vector>
#include <iostream>
using namespace std;

int remove_cnt = 0;

vector<string> check_blocks(int m, int n, vector<string> board) {
	vector<string> copy = board;

	// board����(1,1)���� �����ؼ� �� ĭ�� ���� ���� ������� Ȯ���Ѵ�.
	// 4���� �پ����� ��� �̿� ���� ������Ʈ�� board�� ������ copy �迭���� �Ѵ�.
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			// ���� 2x2 ����� ���� ���� ����̶��
			if ((board[i][j] == board[i - 1][j - 1]) && (board[i][j] == board[i - 1][j]) && (board[i][j] == board[i][j - 1])) {
				// copy �迭���� '0'�� �ƴ� ��쿡�� remove_cnt�� ������Ų��.
				if (copy[i][j] != '0')
					remove_cnt++;
				if (copy[i][j - 1] != '0')
					remove_cnt++;
				if (copy[i - 1][j] != '0')
					remove_cnt++;
				if (copy[i - 1][j - 1] != '0')
					remove_cnt++;
				// copy �迭���� �� ����� '0'���� �ʱ�ȭ�Ѵ�.
				copy[i][j] = copy[i][j-1] = copy[i-1][j] = copy[i-1][j-1] = '0';
			}
		}
	}

	return copy;
}

vector<string> move_blocks(int m, int n, vector<string> board) {
	for (int i = 0; i < n; i++) {
		vector<char> temp;

		// column���� '0'�� �ƴ� �κи� temp �迭�� �ִ´�.
		for (int j = 0; j < m; j++) {
			if (board[j][i] != '0') {
				temp.push_back(board[j][i]);
				board[j][i] = '0';
			}
		}

		// board�� (m - temp �迭�� ����)���� m-1���� temp�� �� ���ҵ��� ���ʷ� �����Ѵ�.
		int idx = 0;
		for (int j = m - (int)temp.size(); j < m; j++)
			board[j][i] = temp[idx++];
	}

	return board;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	while (1) {
		// ���� ����� ����� 2x2 ���·� ���� �� �ִ��� �˻��ϰ� �����.
		remove_cnt = 0;
		board = check_blocks(m, n, board);
		// ������ ����� ���ٸ� while���� �����Ѵ�.
		if (remove_cnt == 0) break;
		// answer�� ������ ����ŭ ���Ѵ�.
		answer += remove_cnt;

		// ������ �κ� ���� �ִ� ��ϵ��� ������ ������.
		board = move_blocks(m, n, board);
	}
	return answer;
}

int main() {
	int m, n;
	string input;
	vector<string> board;
	int answer;

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		cin >> input;
		board.push_back(input);
	}

	answer = solution(m, n, board);
	cout << answer;

	return 0;
}

/*
4 5
CCBDE
AAADE
AAABF
CCBBF

6 6
TTTANT
RRFACC
RRRFCC
TRRRAA
TTMMMF
TMMTTJ
*/