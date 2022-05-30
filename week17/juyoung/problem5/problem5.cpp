#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(string msg) {
	vector<int> answer;
	map<string, int> dictionary;
	int idx = 27;

	// 1. 길이가 1인 모든 단어를 포함하도록 사전을 초기화한다.
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 26; i++)
		dictionary[str.substr(i, 1)] = i + 1;

	for (int m = 0; m < msg.length(); m++) {
		string w = "";

		// 2. 사전에서 현재 입력과 일치하는 가장 긴 문자열 w를 찾는다.
		int i;
		for (i = m; i < msg.length(); i++) {
			w += msg[i];
			if (dictionary[w] > 0) continue;
			else {
				w = w.substr(0, w.length() - 1);
				break;
			}
		}

		// 3. w에 해당하는 사전의 색인 번호를 출력한다.
		// for문을 통해 자동으로 다음 문자를 검색하므로 입력에서 따로 w를 제거하지는 않는다.
		answer.push_back(dictionary[w]);

		// 4. 입력에서 처리되지 않은 다음 글자가 남아있다면(c), w+c에 해당하는 단어를 사전에 등록한다.
		if (m < msg.length() - 1) {
			if (dictionary[w + msg[i]] > 0);
			else dictionary[w + msg[i]] = idx++;
		}

		m = i - 1;
	}

	return answer;
}

int main() {
	string msg;
	vector<int> answer;

	cin >> msg;
	answer = solution(msg);
	
	for (int i = 0; i < (int)answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}

/*
KAKAO
TOBEORNOTTOBEORTOBEORNOT
ABABABABABABABAB
*/