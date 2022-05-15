#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	map<string, vector<int>> table; // key: 조건, value: 점수들

	// 1. info를 map에 담는다.
	for (int i = 0; i < (int)info.size(); i++) {
		string s = info[i];
		stringstream stream;
		string detail[4][2]; // 각 조건을 담는 배열
		int score;

		detail[0][0] = detail[1][0] = detail[2][0] = detail[3][0] = "-";

		// 공백을 기준으로 문자열을 나누고 map에 담을 key를 완성한다.
		stream.str(s);
		for (int j = 0; j < 4; j++) stream >> detail[j][1];
		stream >> score;

		// -를 포함하여 나올 수 있는 모든 key에 점수를 삽입한다.
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				for (int l = 0; l < 2; l++) {
					for (int m = 0; m < 2; m++) {
						string key = detail[0][j] + detail[1][k] + detail[2][l] + detail[3][m];
						table[key].push_back(score);
					}
				}
			}
		}
	}

	// 2. map의 벡터들을 정렬한다.
	// lower_bound() 함수를 수행하기 위해서이다.
	for (auto iter = table.begin(); iter != table.end(); iter++)
		sort(iter->second.begin(), iter->second.end());

	// 3. 각 query를 key 형태로 변환하고 map에서 해당하는 사람의 수를 구한다.
	for (int i = 0; i < (int)query.size(); i++) {
		string curr = query[i];
		stringstream stream;
		string detail[4]; // 각 조건을 담는 배열
		string temp; // "and"를 거르기 위함
		int score;

		// 공백과 and를 제외하고 detail에 삽입한다.
		stream.str(curr);
		stream >> detail[0] >> temp >> detail[1] >> temp >> detail[2] >> temp >> detail[3] >> score;

		// map에서 해당하는 key를 찾고, 점수 조건을 만족하는 사람의 수를 구한다.
		string key = detail[0] + detail[1] + detail[2] + detail[3];
		int cnt = table[key].end() - lower_bound(table[key].begin(), table[key].end(), score);

		answer.push_back(cnt);
	}

	return answer;
}

int main() {
	vector<string> info;
	vector<string> query;
	vector<int> answer;

	info.push_back("java backend junior pizza 150");
	info.push_back("python frontend senior chicken 210");
	info.push_back("python frontend senior chicken 150");
	info.push_back("cpp backend senior pizza 260");
	info.push_back("java backend junior chicken 80");
	info.push_back("python backend senior chicken 50");

	query.push_back("java and backend and junior and pizza 100");
	query.push_back("python and frontend and senior and chicken 200");
	query.push_back("cpp and - and senior and pizza 250");
	query.push_back("- and backend and senior and - 150");
	query.push_back("- and - and - and chicken 100");
	query.push_back("- and - and - and - 150");

	answer = solution(info, query);
	for (int i = 0; i < (int)answer.size(); i++) {
		cout << answer[i] << " ";
	}

	return 0;
}