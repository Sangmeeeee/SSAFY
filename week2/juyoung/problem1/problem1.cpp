#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> A;
int op[4];
int mini = 999999999, maxi = -999999999;
vector<int> s;
int temp = 0;

void make_expression(int cnt) {
	if (cnt == N - 1) {
		temp++;
		vector<int> v(A);
		vector<int> v2(s);
		// °ö¼À, ³ª´°¼À Ã³¸®
		for (int i = 0; i < (int)v2.size(); i++) {
			if (v2[i] == 2) {
				v[i] = v[i] * v[i + 1];
				v.erase(v.begin() + i + 1);
				v2.erase(v2.begin() + i);
				i--;
			}
			else if (v2[i] == 3) {
				v[i] = v[i] / v[i + 1];
				v.erase(v.begin() + i + 1);
				v2.erase(v2.begin() + i);
				i--;
			}
		}
		// µ¡¼À, »¬¼À Ã³¸®
		for (int i = 0; i < (int)v2.size(); i++) {
			if (v2[i] == 0) {
				v[i] = v[i] + v[i + 1];
				v.erase(v.begin() + i + 1);
				v2.erase(v2.begin() + i);
				i--;
			}
			else if (v2[i] == 1) {
				v[i] = v[i] - v[i + 1];
				v.erase(v.begin() + i + 1);
				v2.erase(v2.begin() + i);
				i--;
			}
		}

		if (v[0] > maxi)
			maxi = v[0];
		if (v[0] < mini)
			mini = v[0];
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (op[i] == 0) continue;
		op[i]--;
		s.push_back(i);
		make_expression(cnt + 1);
		op[i]++;
		s.pop_back();
	}
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		A.push_back(input);
	}

	for (int i = 0; i < 4; i++)
		cin >> op[i];

	make_expression(0);

	cout << maxi << "\n" << mini << "\n";

	return 0;
}