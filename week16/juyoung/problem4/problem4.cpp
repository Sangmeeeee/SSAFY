#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <map>
using namespace std;

bool cmp(vector<int> &v1, vector<int> &v2) {
	return v1.size() < v2.size();
}

string getNumber(string s, int i) {
	char c = s[i];
	string num = "";

	// c가 숫자이고, s의 범위를 벗어나지 않는동안 반복한다.
	while ('0' <= c && c <= '9' && i < s.length() - 1) {
		num += c;
		c = s[++i];
	}

	return num;
}

vector<int> solution(string s) {
	vector<int> answer;

	stack<char> bracket;
	vector<vector<int>> elements;
	vector<int> temp;
	for (int i = 1; i < s.length() - 1; i++) {
		if (s[i] == '{') bracket.push('{');
		else if (s[i] == '}') bracket.pop();
		else if ('0' <= s[i] && s[i] <= '9') {
			// 숫자라면, 한자리 수가 아닐 수 있으므로 뒤의 수까지 전부 구한다.
			string num = getNumber(s, i);
			// 자리 수만큼 인덱스 i를 업데이트해준다.
			i += num.length() - 1;
			// num은 string 타입이므로 int형으로 바꿔서 벡터에 삽입한다.
			temp.push_back(stoi(num));
		}
		else if (s[i] == ',') {
			// 콤마라면 스택이 비어있는 경우만 처리하면 된다.
			// 스택이 비어있지 않으면 아직 집합 안이라는 의미이므로 따로 처리해주지 않고 넘기면 된다.
			if (bracket.empty()) {
				// 스택이 비어있다면 어느 한 집합이 끝났음을 의미하므로
				// 현재까지의 벡터를 elements에 삽입하고 temp를 초기화한다.
				elements.push_back(temp);
				temp.clear();
			}
		}
	}

	// 마지막엔 ','가 존재하지 않고 '}'로 끝나기 때문에 마지막 집합을 elements에 삽입해야 한다.
	elements.push_back(temp);
	sort(elements.begin(), elements.end(), cmp);

	map<int, int> m;
	for (int i = 0; i < (int)elements.size(); i++) {
		for (int j = 0; j < (int)elements[i].size(); j++) {
			int n = elements[i][j];
			// map 내에 n이 존재하면 넘어간다. 
			if (m[n] > 0) continue;
			// map 내에 n이 존재하지 않는다면 정답 배열에 삽입하고, map에 추가한다.
			answer.push_back(elements[i][j]);
			m[elements[i][j]] = 1;
			break;
		}
	}

	return answer;
}

int main() {
	string s;
	vector<int> answer;
	
	cin >> s;
	answer = solution(s);
	for (int i = 0; i < (int)answer.size(); i++)
		cout << answer[i] << " ";
	return 0;
}

/*
{{2},{2,1},{2,1,3},{2,1,3,4}}
result -> [2, 1, 3, 4]

{{1,2,3},{2,1},{1,2,4,3},{2}}
result -> [2, 1, 3, 4]

{{20,111},{111}}
result -> [111, 20]

{{123}}
result -> [123]

{{4,2,3},{3},{2,3,4,1},{2,3}}
result -> [3, 2, 4, 1]
*/