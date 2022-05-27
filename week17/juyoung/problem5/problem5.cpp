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

	// 1. ���̰� 1�� ��� �ܾ �����ϵ��� ������ �ʱ�ȭ�Ѵ�.
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	for (int i = 0; i < 26; i++)
		dictionary[str.substr(i, 1)] = i + 1;

	for (int m = 0; m < msg.length(); m++) {
		string w = "";

		// 2. �������� ���� �Է°� ��ġ�ϴ� ���� �� ���ڿ� w�� ã�´�.
		int i;
		for (i = m; i < msg.length(); i++) {
			w += msg[i];
			if (dictionary[w] > 0) continue;
			else {
				w = w.substr(0, w.length() - 1);
				break;
			}
		}

		// 3. w�� �ش��ϴ� ������ ���� ��ȣ�� ����Ѵ�.
		// for���� ���� �ڵ����� ���� ���ڸ� �˻��ϹǷ� �Է¿��� ���� w�� ���������� �ʴ´�.
		answer.push_back(dictionary[w]);

		// 4. �Է¿��� ó������ ���� ���� ���ڰ� �����ִٸ�(c), w+c�� �ش��ϴ� �ܾ ������ ����Ѵ�.
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