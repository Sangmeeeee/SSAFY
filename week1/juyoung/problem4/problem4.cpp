#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> sensor;	// 센서 위치 저장
vector<int> diff;	// 센서 간의 거리 저장
int answer = 0;

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int location;
		cin >> location;
		sensor.push_back(location);
	}

	// 센서의 위치를 오름차순으로 정렬하고 중복 제거
	sort(sensor.begin(), sensor.end());
	sensor.erase(unique(sensor.begin(), sensor.end()), sensor.end());

	// 인접한 센서 간의 거리 계산 후 저장
	for (int i = 0; i < (int)sensor.size() - 1; i++)
		diff.push_back(sensor[i + 1] - sensor[i]);

	// 센서 간의 거리 오름차순으로 정렬
	// 정렬한 벡터의 제일 뒤에서 (집중국의 수-1)만큼은 빼고 전부 더한 것이 답
	sort(diff.begin(), diff.end());
	for (int i = 0; i < (int)diff.size() - K + 1; i++)
		answer += diff[i];

	cout << answer;

	return 0;
}
