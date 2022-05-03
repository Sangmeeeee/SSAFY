#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	stringstream ss;
	string action, userid, nickname;
	map<string, string> users;  // string: ���̵�, string: �г���
	vector<string> uid;			// ���� ��¿��� ������ ���̵� ���

	for (int i = 0; i < (int)record.size(); i++) {
		ss.str(record[i]);
		ss >> action;
		if (action == "Enter") {
			// ä�ù濡 ���Դٸ� ���̵�� �г��� �Է� �ޱ�
			ss >> userid >> nickname;
			users[userid] = nickname;
			uid.push_back(userid);
			answer.push_back("���� ���Խ��ϴ�.");
		}
		else if (action == "Leave") {
			// ä�ù��� �����ٸ� ���̵� �Է� �ޱ�
			ss >> userid;
			uid.push_back(userid);
			answer.push_back("���� �������ϴ�.");
		}
		else {
			// �г����� �����Ѵٸ� ���̵�� ������ �г��� �Է� �ޱ�
			ss >> userid >> nickname;
			users[userid] = nickname;
		}

		ss.clear();
	}

	for (int i = 0; i < (int)answer.size(); i++) {
		// ���̵� �´� �г��� + "���� ����/�������ϴ�."
		answer[i].insert(0, users[uid[i]]);
	}

	return answer;
}

int main() {
	vector<string> record;
	vector<string> answer;
	
	record.push_back("Enter uid1234 Muzi");
	record.push_back("Enter uid4567 Prodo");
	record.push_back("Leave uid1234");
	record.push_back("Enter uid1234 Prodo");
	record.push_back("Change uid4567 Ryan");

	answer = solution(record);
	for (int i = 0; i < (int)answer.size(); i++)
		cout << answer[i] << "\n";

	return 0;
}