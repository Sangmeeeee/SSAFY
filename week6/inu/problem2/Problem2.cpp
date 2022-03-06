#include <iostream>
#include <vector>

using namespace std;

vector<string> gear;

void rotate(int num, int dir) {
	char c;
	if (dir == 1) {
		c = gear[num].back();
		gear[num].pop_back();
		gear[num] = c + gear[num];
	}
	else {
		char last = gear[num].front();
		gear[num] = gear[num].substr(1);
		gear[num].push_back(last);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	gear.push_back("");
	for (int i = 0; i < 4; i++) {
		string s;
		cin >> s;
		gear.push_back(s);
	}

	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int num, dir;
		int v[5] = { 0, };

		cin >> num >> dir;
		v[num] = dir;

		for (int i = num; i > 1; i--) {
			if (gear[i - 1][2] == gear[i][6])
				break;
			v[i - 1] = v[i] == 1 ? -1 : 1;
		}
		
		for (int i = num; i < 4; i++) {
			if (gear[i][2] == gear[i + 1][6])
				break;
			v[i + 1] = v[i] == 1 ? -1 : 1;
		}
		
		for(int i = 1; i <= 4; i++)
			if(v[i] != 0)
				rotate(i, v[i]);
	}

	int sum = 0;
	for (int i = 1; i <= 4; i++) {
		if (gear[i][0] == '1')
			sum += pow(2, i - 1);
	}

	cout << sum;

	return 0;
}