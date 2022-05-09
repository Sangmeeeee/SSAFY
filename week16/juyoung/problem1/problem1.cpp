#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	vector<string> total; // ��ü ���ڿ�
	map<string, int> A, B; // ���� A, B
	int inter = 0, uni = 0; // ������, ������ ����

	//  1. str1���� �� ���ھ� ����
	for (int i = 0; i < str1.length() - 1; i++) {
		string temp = str1.substr(i, 2);

		// �ҹ��ڷ� ��ȯ
		temp[0] = tolower(temp[0]);
		temp[1] = tolower(temp[1]);

		// �����̳� ����, Ư�� ���ڰ� ����ִ� ��� ���� ���� ������.
		if (temp[0] < 'a' || temp[0] > 'z') continue;
		if (temp[1] < 'a' || temp[1] > 'z') continue;

		// map�� �ִ� ���� �ƴϸ� ��ü ���ڿ��� �߰��Ѵ�.
		if (A[temp] == 0) total.push_back(temp);
		A[temp]++;
	}

	//  2. str2���� �� ���ھ� ����
	for (int i = 0; i < str2.length() - 1; i++) {
		string temp = str2.substr(i, 2);

		// �ҹ��ڷ� ��ȯ
		temp[0] = tolower(temp[0]);
		temp[1] = tolower(temp[1]);

		// �����̳� ����, Ư�� ���ڰ� ����ִ� ��� ���� ���� ������.
		if (temp[0] < 'a' || temp[0] > 'z') continue;
		if (temp[1] < 'a' || temp[1] > 'z') continue;

		// map�� �ִ� ���� �ƴϸ� ��ü ���ڿ��� �߰��Ѵ�.
		if (A[temp] == 0 && B[temp] == 0) total.push_back(temp);
		B[temp]++;
	}
	
	// 3. �� �� �������̶�� 65536�� ��ȯ�Ѵ�.
	if (A.empty() && B.empty()) return 65536;

	// 4. ��ü ���ڿ��� Ž���ϸ鼭 ������, ������ ������ ���Ѵ�.
	for (int i = 0; i < (int)total.size(); i++) {
		string temp = total[i];
		// �������� ������ �� ������ ������ �ش� ���ڿ��� ���� �� �� ���� ���̴�.
		inter += min(A[temp], B[temp]);
		// �������� ������ �� ������ ������ �ش� ���ڿ��� ���� �� �� ū ���̴�.
		uni += max(A[temp], B[temp]);
	}

	// 5. ������ ���Ѵ�.
	double value = (double)inter / uni;
	answer = (int)(value * 65536);

	return answer;
}

int main() {
	string str1, str2;
	int answer;

	getline(cin, str1);
	getline(cin, str2);
	answer = solution(str1, str2);
	cout << answer;

	return 0;
}

/*
FRANCE
french
answer: 16384

handshake
shake hands
answer: 65536

aa1+aa2
AAAA12
answer: 43690

E=M*C^2
e=m*c^2
answer: 65536
*/