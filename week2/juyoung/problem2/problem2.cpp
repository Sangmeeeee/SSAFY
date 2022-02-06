#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
	int answer = 0;
	queue<int> wait;
	queue<int> ing;

	for (int i = 0; i < (int)truck_weights.size(); i++)
		wait.push(truck_weights[i]);
	for (int i = 0; i < bridge_length; i++)
		ing.push(0);

	int t_weight = 0;
	while (1) {
		if (ing.empty()) break;

		// ing ť�� front ���� 0�� �ƴ϶�� Ʈ���� �ٸ��� ���������� ��
		if (ing.front() != 0)
			t_weight -= ing.front();
		ing.pop();

		// wait�� ����ٸ� ing���� pop �۾��� ���ָ� ��
		if (wait.empty()) {
			answer++; 
			continue;
		}

		// wait ť�� front ���� ���� ���� �� Ʈ���� ���Ը� ������ ��
		// �ٸ��� ������ �� �ִ� ���Ժ��� ũ�ٸ� 0�� ing ť�� push
		if (t_weight + wait.front() > weight) {
			ing.push(0);
		}
		else { // �ƴ϶�� wait ť�� front ���� push�ϰ� wait ť pop
			ing.push(wait.front());
			t_weight += wait.front();
			wait.pop();
		}
		answer++;
	}

	return answer;
}

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	int b, w;
	vector<int> t;

	//cin >> b >> w;
	t.push_back(7);
	t.push_back(4);
	t.push_back(5);
	t.push_back(6);

	cout << solution(2, 10, t);
	
	return 0;
}