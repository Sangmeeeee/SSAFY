#include <string>
#include <vector>
#include <sstream>
#include <cctype>
#include <iostream>
using namespace std;

// '#'�� ���� ������ �ҹ��ڷ� ġȯ�Ѵ�.
// ex) C# -> c
string change(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == '#') {
			str[i - 1] = tolower(str[i - 1]);
			str.erase(str.begin() + i);
			i--;
		}
	}

	return str;
}

string solution(string m, vector<string> musicinfos) {
	string answer = "";

	int max_play = 0;
	for (int i = 0; i < (int)musicinfos.size(); i++) {
		vector<string> info;
		int shour, smin; // ���� �ð�, ��
		int ehour, emin; // �� �ð�, ��
		int playtime = 0; // ��� �ð�(��)

		stringstream ss(musicinfos[i]);
		string token;
		while (getline(ss, token, ','))
			info.push_back(token);

		shour = stoi(info[0].substr(0, 2));
		smin = stoi(info[0].substr(3, 2));
		ehour = stoi(info[1].substr(0, 2));
		emin = stoi(info[1].substr(3, 2));

		// ��� �ð� ���
		playtime = ehour * 60 + emin - shour * 60 - smin;

		// '#'�� ���Ե� ���� ġȯ
		m = change(m);
		info[3] = change(info[3]);

		string note = "";
		// if: ���� ��� �ð����� �� ���
		// else: ���� ��� �ð����� ª�� ���
		if (info[3].length() > playtime)
			note = info[3].substr(0, playtime);
		else {
			for (int j = 0; j <= playtime / info[3].length(); j++)
				note += info[3];
			note = note.substr(0, playtime);
		}

		// �׿��� ���� ������ ���̰� ��� ��ٸ� �н��Ѵ�.
		if (m.length() > note.length()) continue;

		for (int j = 0; j <= note.length() - m.length(); j++) {
			// �߶� ���ڿ��� �׿��� ���� ���ǰ� ���ٸ�
			if (note.substr(j, m.length()) == m) {
				// max_play�� ���ϰ�, ���� ��� �ð��� �� ��ٸ� �������� ������Ʈ �Ѵ�.
				if (max_play < playtime) {
					max_play = playtime;
					answer = info[2];
				}
				break;
			}
		}
	}

	if (max_play == 0) answer = "(None)";
	return answer;
}

int main() {
	string m;
	vector<string> musicinfos;
	string answer;

	m = "CCB";
	musicinfos.push_back("03:00,03:10,FOO,CCB#CCB");
	musicinfos.push_back("04:00,04:08,BAR,ABC");

	answer = solution(m, musicinfos);
	cout << answer;

	return 0;
}

/*
m = "ABCDEFG";
musicinfos.push_back("12:00,12:14,HELLO,CDEFGAB");
musicinfos.push_back("13:00,13:05,WORLD,ABCDEF");

m = "CC#BCC#BCC#BCC#B";
musicinfos.push_back("03:00,03:30,FOO,CC#B");
musicinfos.push_back("04:00,04:08,BAR,CC#BCC#BCC#B");

m = "ABC";
musicinfos.push_back("12:00,12:14,HELLO,C#DEFGAB");
musicinfos.push_back("13:00,13:05,WORLD,ABCDEF");

m = "CCB";
musicinfos.push_back("03:00,03:10,FOO,CCB#CCB");
musicinfos.push_back("04:00,04:08,BAR,ABC");
*/