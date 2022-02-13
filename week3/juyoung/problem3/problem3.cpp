#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string order;
int C;
map<string, int> m;
int maximum;

void make_all_course(int idx, string temp) {
	if (temp.length() == C) {
		m[temp]++;
		return;
	}
	for (int i = idx; i < order.length(); i++){
		make_all_course(i + 1, temp + order[i]);
	}
}

vector<string> solution(vector<string> orders, vector<int> course) {
	vector<string> answer;

	for (int c = 0; c < (int)course.size(); c++) {
		C = course[c];
		for (int i = 0; i < (int)orders.size(); i++) {
			order = orders[i];
			sort(order.begin(), order.end());	// �ֹ� ������ ���� �ʼ�
			make_all_course(0, "");				// �ش� �ֹ����� C���� �̴� ��� ���� ���ϱ�
		}

		// value �������� �����ϱ� ���� vector�� map ����
		vector<pair<string, int>> v(m.begin(), m.end());
		sort(v.begin(), v.end(), [](pair<string, int> a, pair<string, int> b) {
			return a.second > b.second; // �������� ����
		});

		// ���� ���� �ֹ��� ���� answer�� ����
		if(!v.empty()) maximum = v[0].second;
		for (int i = 0; i < (int)v.size(); i++) {
			if (maximum < 2 || v[i].second < maximum) break;
			answer.push_back(v[i].first);
		}

		// map �ʱ�ȭ
		m.erase(m.begin(), m.end());
	}

	sort(answer.begin(), answer.end());

	return answer;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int order, course;
	vector<string> v1;
	vector<int> v2;

	cin >> order;
	for (int i = 0; i < order; i++) {
		string temp;
		cin >> temp;
		v1.push_back(temp);
	}

	cin >> course;
	for (int i = 0; i < course; i++) {
		int temp;
		cin >> temp;
		v2.push_back(temp);
	}

	vector<string> answer = solution(v1, v2);
	for (int i = 0; i < (int)answer.size(); i++)
		cout << answer[i] << " ";

	return 0;
}
/*
6
ABCFG AC CDE ACDE BCFG ACDEH
3
2 3 4

7
ABCDE AB CD ADE XYZ XYZ ACD
3
2 3 5

3
XYZ XWY WXA
3
2 3 4
*/