#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(string s) {
	vector<int> answer;
	int flag[100001] = { 0, };

	string number;
	for (int i = 0; i < s.length(); i++) {
		if ('0' <= s[i] && s[i] <= '9') {
			number += s[i];
		}
		else {
			// 만약 number에 숫자가 저장되어 있다면
			if (number.length()) {
				// flag 배열에서 number에 해당하는 인덱스의 값을 1만큼 증가시킨다.
				flag[stoi(number)]++;
				number.clear();
			}
		}
	}

	vector<pair<int, int>> numbers;
	for (int i = 0; i < 100001; i++) {
		if (flag[i]) numbers.push_back({ flag[i], i });
	}

	sort(numbers.begin(), numbers.end());

	for (int i = (int)numbers.size() - 1; i >= 0; i--)
		answer.push_back(numbers[i].second);

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