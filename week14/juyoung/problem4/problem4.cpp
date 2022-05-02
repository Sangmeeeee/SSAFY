#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	string s;
	map<string, double> m;
	double cnt = 0; // 전체 개수

	// 더이상 입력이 없을 때까지(EOF까지)
	while (getline(cin, s)) {
		m[s]++;
		cnt++;
	}

	//소수점 이하의 자릿수만을 다룰 수 있게 설정한다.
	cout << fixed; 
	// 만약 위 fixed 설정이 없으면 정수와 소수를 합쳐서 4자리를 나타낸다.
	// 하지만 fixed 설정을 해줬으므로 소수점 아래 4자리를 나타내준다.
	cout.precision(4);

	// map을 순회하며 출력한다.
	auto iter = m.begin();
	while (iter != m.end()) {
		double p = (iter->second / cnt) * 100;
		cout << iter->first << " " << p << "\n";
		iter++;
	}

	return 0;
}