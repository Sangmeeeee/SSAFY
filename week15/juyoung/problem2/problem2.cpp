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
	map<string, string> users;  // string: 아이디, string: 닉네임
	vector<string> uid;			// 최종 출력에서 참조할 아이디 목록

	for (int i = 0; i < (int)record.size(); i++) {
		ss.str(record[i]);
		ss >> action;
		if (action == "Enter") {
			// 채팅방에 들어왔다면 아이디와 닉네임 입력 받기
			ss >> userid >> nickname;
			users[userid] = nickname;
			uid.push_back(userid);
			answer.push_back("님이 들어왔습니다.");
		}
		else if (action == "Leave") {
			// 채팅방을 나갔다면 아이디만 입력 받기
			ss >> userid;
			uid.push_back(userid);
			answer.push_back("님이 나갔습니다.");
		}
		else {
			// 닉네임을 변경한다면 아이디와 변경할 닉네임 입력 받기
			ss >> userid >> nickname;
			users[userid] = nickname;
		}

		ss.clear();
	}

	for (int i = 0; i < (int)answer.size(); i++) {
		// 아이디에 맞는 닉네임 + "님이 들어왔/나갔습니다."
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