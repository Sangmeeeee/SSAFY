#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
	vector<int> answer;
	map<string, vector<int>> table; // key: ����, value: ������

	// 1. info�� map�� ��´�.
	for (int i = 0; i < (int)info.size(); i++) {
		string s = info[i];
		stringstream stream;
		string detail[4][2]; // �� ������ ��� �迭
		int score;

		detail[0][0] = detail[1][0] = detail[2][0] = detail[3][0] = "-";

		// ������ �������� ���ڿ��� ������ map�� ���� key�� �ϼ��Ѵ�.
		stream.str(s);
		for (int j = 0; j < 4; j++) stream >> detail[j][1];
		stream >> score;

		// -�� �����Ͽ� ���� �� �ִ� ��� key�� ������ �����Ѵ�.
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

	// 2. map�� ���͵��� �����Ѵ�.
	// lower_bound() �Լ��� �����ϱ� ���ؼ��̴�.
	for (auto iter = table.begin(); iter != table.end(); iter++)
		sort(iter->second.begin(), iter->second.end());

	// 3. �� query�� key ���·� ��ȯ�ϰ� map���� �ش��ϴ� ����� ���� ���Ѵ�.
	for (int i = 0; i < (int)query.size(); i++) {
		string curr = query[i];
		stringstream stream;
		string detail[4]; // �� ������ ��� �迭
		string temp; // "and"�� �Ÿ��� ����
		int score;

		// ����� and�� �����ϰ� detail�� �����Ѵ�.
		stream.str(curr);
		stream >> detail[0] >> temp >> detail[1] >> temp >> detail[2] >> temp >> detail[3] >> score;

		// map���� �ش��ϴ� key�� ã��, ���� ������ �����ϴ� ����� ���� ���Ѵ�.
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