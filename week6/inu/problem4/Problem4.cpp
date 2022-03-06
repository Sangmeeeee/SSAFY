#include <iostream>

using namespace std;

string reverse(string origin) {
	string re;

	for (int i = (int)origin.size() - 1; i >= 0; i--) {
		re.push_back(origin[i]);
		origin.pop_back();
	}

	return re;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string origin, target;
	cin >> origin >> target;

	int answer = 1;
	int o_size = (int)origin.size();
	int idx = (int)target.size() - 1;

	while (1) {
		char c = target[idx];
		target.pop_back();
		if (c == 'B')
			target = reverse(target);
		idx--;
		
		if (o_size == idx + 1) {
			if (origin.compare(target))
				answer = 0;
			break;
		}
	}

	cout << answer;

	return 0;
}