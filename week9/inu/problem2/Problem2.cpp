#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	vector<vector<int>> LCS;

	cin >> s1 >> s2;

	int len1 = (int)s1.length();
	int len2 = (int)s2.length();

	LCS.assign(len1 + 1,
		vector<int>(len2 + 1, 0));

	for (int i = 1; i <= len1; i++) {
		for (int j = 1; j <= len2; j++) {
			if (s1[i - 1] == s2[j - 1])
				LCS[i][j] = LCS[i - 1][j - 1] + 1;
			else
				LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}

	cout << LCS[len1][len2];

	return 0;
}