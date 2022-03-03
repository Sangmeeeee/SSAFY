#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	string S, T;

	cin >> S >> T;

	while (S.length() != T.length()) {
		int len = T.length();

		if (T[len - 1] == 'A')
			T.erase(len - 1);
		else {
			T.erase(len - 1);
			reverse(T.begin(), T.end());
		}
	}

	if (S == T) cout << 1;
	else cout << 0;

	return 0;
}