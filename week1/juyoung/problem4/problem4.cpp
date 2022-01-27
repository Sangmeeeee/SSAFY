#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, K;
vector<int> sensor;	// ���� ��ġ ����
vector<int> diff;	// ���� ���� �Ÿ� ����
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

	// ������ ��ġ�� ������������ �����ϰ� �ߺ� ����
	sort(sensor.begin(), sensor.end());
	sensor.erase(unique(sensor.begin(), sensor.end()), sensor.end());

	// ������ ���� ���� �Ÿ� ��� �� ����
	for (int i = 0; i < (int)sensor.size() - 1; i++)
		diff.push_back(sensor[i + 1] - sensor[i]);

	// ���� ���� �Ÿ� ������������ ����
	// ������ ������ ���� �ڿ��� (���߱��� ��-1)��ŭ�� ���� ���� ���� ���� ��
	sort(diff.begin(), diff.end());
	for (int i = 0; i < (int)diff.size() - K + 1; i++)
		answer += diff[i];

	cout << answer;

	return 0;
}
