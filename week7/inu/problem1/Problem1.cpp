#include <iostream>
#include <vector>

using namespace std;

int N, M;
int person[50001]; // i¹øÂ°±îÁöÀÇ ½Â°´ ÇÕ
int maxPerson[4][50001]; // i¹øÂ° ¼ÒÇü ±â°üÂ÷°¡ j¹øÂ° °´Â÷±îÁö ºÃÀ» ¶§ ÃÖ´ë ½Â°´ ¼ö

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		person[i] = person[i - 1] + num;
	}

	cin >> M;
	for (int i = 1; i <= 3; i++) {
		for (int j = i * M; j <= N; j++) {
			maxPerson[i][j] = max(maxPerson[i][j - 1],
				maxPerson[i - 1][j - M] + (person[j] - person[j - M]));
		}
	}

	cout << maxPerson[3][N];

	return 0;
}