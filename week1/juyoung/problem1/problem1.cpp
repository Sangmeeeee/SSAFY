#include <iostream>
#include <string>
using namespace std;

int main() {
	string str, explosion;
	string answer = "";

	cin >> str >> explosion;

	for (int i = 0; i < str.length(); i++) {
		answer.push_back(str[i]);
		if (answer.back() != explosion.back()) continue;
		if (answer.length() < explosion.length()) continue;

		if (answer.substr(answer.length() - explosion.length(), explosion.length()) != explosion)
			continue;
		
		for (int j = 0; j < explosion.length(); j++)
			answer.pop_back();
	}

	if (answer.empty())	cout << "FRULA";
	else				cout << answer;

	return 0;
}
