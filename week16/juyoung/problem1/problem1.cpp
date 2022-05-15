#include <string>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	vector<string> total; // 전체 문자열
	map<string, int> A, B; // 집합 A, B
	int inter = 0, uni = 0; // 교집합, 합집합 개수

	//  1. str1에서 두 글자씩 끊기
	for (int i = 0; i < str1.length() - 1; i++) {
		string temp = str1.substr(i, 2);

		// 소문자로 변환
		temp[0] = tolower(temp[0]);
		temp[1] = tolower(temp[1]);

		// 공백이나 숫자, 특수 문자가 들어있는 경우 글자 쌍을 버린다.
		if (temp[0] < 'a' || temp[0] > 'z') continue;
		if (temp[1] < 'a' || temp[1] > 'z') continue;

		// map에 있는 값이 아니면 전체 문자열에 추가한다.
		if (A[temp] == 0) total.push_back(temp);
		A[temp]++;
	}

	//  2. str2에서 두 글자씩 끊기
	for (int i = 0; i < str2.length() - 1; i++) {
		string temp = str2.substr(i, 2);

		// 소문자로 변환
		temp[0] = tolower(temp[0]);
		temp[1] = tolower(temp[1]);

		// 공백이나 숫자, 특수 문자가 들어있는 경우 글자 쌍을 버린다.
		if (temp[0] < 'a' || temp[0] > 'z') continue;
		if (temp[1] < 'a' || temp[1] > 'z') continue;

		// map에 있는 값이 아니면 전체 문자열에 추가한다.
		if (A[temp] == 0 && B[temp] == 0) total.push_back(temp);
		B[temp]++;
	}
	
	// 3. 둘 다 공집합이라면 65536을 반환한다.
	if (A.empty() && B.empty()) return 65536;

	// 4. 전체 문자열을 탐색하면서 교집합, 합집합 개수를 구한다.
	for (int i = 0; i < (int)total.size(); i++) {
		string temp = total[i];
		// 교집합의 개수는 두 집합이 가지는 해당 문자열의 개수 중 더 적은 것이다.
		inter += min(A[temp], B[temp]);
		// 합집합의 개수는 두 집합이 가지는 해당 문자열의 개수 중 더 큰 것이다.
		uni += max(A[temp], B[temp]);
	}

	// 5. 정답을 구한다.
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