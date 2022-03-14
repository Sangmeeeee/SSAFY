#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int N;
	vector<int> arr;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int input;
		cin >> input;
		arr.push_back(input);
	}

	sort(arr.begin(), arr.end());

	int min_value = 2000000000;
	pair<int, int> answer;
	int left = 0, right = N - 1;
	while (left != right) {
		if (min_value > abs(arr[left] + arr[right])) {
			min_value = abs(arr[left] + arr[right]);
			answer.first = arr[left];
			answer.second = arr[right];
		}

		int val1 = abs(arr[left] + arr[right - 1]);
		int val2 = abs(arr[left + 1] + arr[right]);

		if (val1 < val2)
			right--;
		else
			left++;
	}

	cout << answer.first << " " << answer.second;
	return 0;
}