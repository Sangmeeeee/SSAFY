#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	int weight[1000];
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> weight[i];
	sort(weight, weight + N);


	int start = 1;
	for (int i = 0; i < N; i++) {
		if (start < weight[i])
			break;
		start += weight[i];
	}

	cout << start;
	return 0;
}