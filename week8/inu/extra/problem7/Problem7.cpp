#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int G;
	int i = 1, j = 1;
	vector<int> weight;

	cin >> G;

	int n = 1;
	while (n * n < G) n++;
	j = n;

	while (i < j) {
		if (j * j - i * i <= G) {
			if (j * j - i * i == G)
				weight.push_back(j);
			j++;
		}
		else
			i++;
	}

	if ((int)weight.size() == 0)
		cout << -1;
	else
		for (int i = 0; i < (int)weight.size(); i++)
			cout << weight[i] << '\n';

	return 0;
}