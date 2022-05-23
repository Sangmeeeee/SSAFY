#include <string>
#include <vector>
#include <iostream>
using namespace std;

int remove_cnt = 0;

vector<string> check_blocks(int m, int n, vector<string> board) {
	vector<string> copy = board;

	// board에서(1,1)부터 시작해서 네 칸이 전부 같은 블록인지 확인한다.
	// 4개가 붙어있을 경우 이에 대한 업데이트는 board를 복사한 copy 배열에서 한다.
	for (int i = 1; i < m; i++) {
		for (int j = 1; j < n; j++) {
			// 만약 2x2 블록이 전부 같은 블록이라면
			if ((board[i][j] == board[i - 1][j - 1]) && (board[i][j] == board[i - 1][j]) && (board[i][j] == board[i][j - 1])) {
				// copy 배열에서 '0'이 아닌 경우에만 remove_cnt를 증가시킨다.
				if (copy[i][j] != '0')
					remove_cnt++;
				if (copy[i][j - 1] != '0')
					remove_cnt++;
				if (copy[i - 1][j] != '0')
					remove_cnt++;
				if (copy[i - 1][j - 1] != '0')
					remove_cnt++;
				// copy 배열에서 각 블록을 '0'으로 초기화한다.
				copy[i][j] = copy[i][j-1] = copy[i-1][j] = copy[i-1][j-1] = '0';
			}
		}
	}

	return copy;
}

vector<string> move_blocks(int m, int n, vector<string> board) {
	for (int i = 0; i < n; i++) {
		vector<char> temp;

		// column별로 '0'이 아닌 부분만 temp 배열에 넣는다.
		for (int j = 0; j < m; j++) {
			if (board[j][i] != '0') {
				temp.push_back(board[j][i]);
				board[j][i] = '0';
			}
		}

		// board의 (m - temp 배열의 길이)부터 m-1까지 temp에 든 원소들을 차례로 복사한다.
		int idx = 0;
		for (int j = m - (int)temp.size(); j < m; j++)
			board[j][i] = temp[idx++];
	}

	return board;
}

int solution(int m, int n, vector<string> board) {
	int answer = 0;

	while (1) {
		// 같은 모양의 블록이 2x2 형태로 붙은 게 있는지 검사하고 지운다.
		remove_cnt = 0;
		board = check_blocks(m, n, board);
		// 지워진 블록이 없다면 while문을 종료한다.
		if (remove_cnt == 0) break;
		// answer에 지워진 수만큼 더한다.
		answer += remove_cnt;

		// 지워진 부분 위에 있는 블록들을 밑으로 내린다.
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