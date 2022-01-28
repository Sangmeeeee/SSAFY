#include <string>
#include <vector>
using namespace std;

int solution(string s) {
	int answer = 0;

	for (int i = 0; i < s.size(); i++) {
		int n = s[0];
		s.erase(0, 1);
		s.push_back(n);
		cout << s << "\n";
	}

	return answer;
}

int main() {
	solution("[](){}");
	return 0;
}