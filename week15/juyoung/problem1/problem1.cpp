#include <iostream>
#include <string>
using namespace std;

int solution(string s) {
	int answer = s.length(); // 하나도 압축되지 않은 길이로 초기화
	int len = 1;			 // 자를 문자의 개수

	// 자를 수 있는 문자의 개수는 최대 s.length()/2개이다.
	// ex. ababcdcdababcdcd => 2ababcbcb
	// len이 s.length()의 절반보다 작은동안 수행한다.
	while (len <= s.length()/2) {
		string temp;	// 압축할 단위 문자열
		string ans_str;	// 압축한 문자열을 저장하는 변수
		int cnt = 1;	// 압축할 수 있는 개수

		// 1. 처음부터 len만큼 잘라낸다.
		temp = s.substr(0, len);

		// 2. 문자열 s를 탐색한다.
		for (int i = len; i < s.length(); i+=len) {
			if (temp == s.substr(i, len)) {
				// 2-1. temp와 현재 인덱스(i)부터 len만큼 잘라낸 문자열이 같다면
				// 압축할 수 있는 개수가 늘어난다.
				cnt++;
			}
			else {
				// 2-2-1. 아니라면 temp의 압축 개수와 temp를 ans_str에 문자 형태로 붙인다.
				if (cnt > 1) ans_str += to_string(cnt);
				ans_str += temp;

				// 2-2-2. 현재 위치에서 다시 len만큼 자른 문자열을 temp에 저장하여
				// 다음부터는 이를 기준으로 문자열을 압축하도록 한다.
				temp = s.substr(i, len);
				cnt = 1;
			}
		}

		// 3. for문을 돌다보면 마지막 temp가 ans_str에 합쳐지지 않은 채로 종료된다.
		// 따라서 ans_str에 temp를 합치는 작업이 필요하다.
		// 이때 cnt가 1보다 큰 상태이면 cnt 또한 temp와 함께 ans_str에 문자 형태로 합쳐야 한다.
		if (cnt > 1) ans_str += to_string(cnt);
		ans_str += temp;

		// 4. 현재 answer보다 ans_str의 길이가 작다면, ans_str의 길이를 answer에 저장한다.
		// answer에는 현재까지 압축한 문자열 중 가장 길이가 짧은 문자열의 길이가 저장되어 있다.
		if (answer > ans_str.length())
			answer = ans_str.length();

		// 5. len을 1만큼 늘려 while문을 반복한다.
		len++;
	}

	return answer;
}

int main() {
	string s;
	cin >> s;

	cout << solution(s);

	return 0;
}