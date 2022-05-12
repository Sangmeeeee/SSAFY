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

	// c�� �����̰�, s�� ������ ����� �ʴµ��� �ݺ��Ѵ�.
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
			// ���ڶ��, ���ڸ� ���� �ƴ� �� �����Ƿ� ���� ������ ���� ���Ѵ�.
			string num = getNumber(s, i);
			// �ڸ� ����ŭ �ε��� i�� ������Ʈ���ش�.
			i += num.length() - 1;
			// num�� string Ÿ���̹Ƿ� int������ �ٲ㼭 ���Ϳ� �����Ѵ�.
			temp.push_back(stoi(num));
		}
		else if (s[i] == ',') {
			// �޸���� ������ ����ִ� ��츸 ó���ϸ� �ȴ�.
			// ������ ������� ������ ���� ���� ���̶�� �ǹ��̹Ƿ� ���� ó�������� �ʰ� �ѱ�� �ȴ�.
			if (bracket.empty()) {
				// ������ ����ִٸ� ��� �� ������ �������� �ǹ��ϹǷ�
				// ��������� ���͸� elements�� �����ϰ� temp�� �ʱ�ȭ�Ѵ�.
				elements.push_back(temp);
				temp.clear();
			}
		}
	}

	// �������� ','�� �������� �ʰ� '}'�� ������ ������ ������ ������ elements�� �����ؾ� �Ѵ�.
	elements.push_back(temp);
	sort(elements.begin(), elements.end(), cmp);

	map<int, int> m;
	for (int i = 0; i < (int)elements.size(); i++) {
		for (int j = 0; j < (int)elements[i].size(); j++) {
			int n = elements[i][j];
			// map ���� n�� �����ϸ� �Ѿ��. 
			if (m[n] > 0) continue;
			// map ���� n�� �������� �ʴ´ٸ� ���� �迭�� �����ϰ�, map�� �߰��Ѵ�.
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