#include <string>
#include <vector>
#include <map>
using namespace std;

int row, col;
int comb[8]; // 후보키로 사용할 컬럼의 조합을 저장한다.
vector<vector<int>> keyList; // 후보키 목록을 저장한다.

void makeComb(vector<vector<string>> relation, int cnt, int idx, int n) {
	if (cnt == n) {
		// 만든 조합에 해당하는 컬럼을 하나의 문자열로 합쳐서 map에 넣는다. 
		map<string, string> m;
		for (int i = 0; i < row; i++) {
			// 만든 조합에 해당하는 컬럼을 하나의 문자열로 합쳐서 map에 넣는다.
			string str = "";
			for (int j = 0; j < n; j++) {
				str += relation[i][comb[j]];
			}
			m[str] = str;
		}

		// row 개수와 같은지(유일성을 만족하는지) 검사한다. 
		if (m.size() == row) {
			vector<int> temp;
			for (int i = 0; i < n; i++)
				temp.push_back(comb[i]);
			keyList.push_back(temp);
		}

		return;
	}

	for (int i = idx; i < col; i++) {
		comb[cnt] = i;
		makeComb(relation, cnt + 1, i + 1, n);
	}
}

int solution(vector<vector<string>> relation) {
	int answer = 0;

	row = relation.size();    // 행의 개수
	col = relation[0].size(); // 열의 개수

	// 유일성을 만족하는 후보키 목록을 keyList에 저장한다.
	// 컬럼의 개수별로 후보키를 만든다.
	for (int j = 1; j <= col; j++)
		makeComb(relation, 0, 0, j);

	// 최소성을 만족하도록 keyList를 수정한다.
	for (int i = 0; i < keyList.size(); i++) {
		int cnt = 0; // keyList[j]가 keyList[i] 중 몇 가지를 포함하는지 저장한다.
		for (int j = i + 1; j < keyList.size(); j++) {
			for (int k = 0; k < keyList[i].size(); k++) {
				for (int l = k; l < keyList[j].size(); l++) {
					if (keyList[i][k] == keyList[j][l])
						cnt++;
				}
			}
			// keyList[j]가 keyList[i]의 모든 원소를 포함하고 있다면, keyList[j]를 지운다.
			if (cnt == keyList[i].size()) {
				keyList.erase(keyList.begin() + j);
				j--;
			}
			cnt = 0;
		}
	}

	answer = keyList.size();

	return answer;
}