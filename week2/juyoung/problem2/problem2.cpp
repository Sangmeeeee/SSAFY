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

		// ing 큐의 front 값이 0이 아니라면 트럭이 다리를 빠져나가는 것
		if (ing.front() != 0)
			t_weight -= ing.front();
		ing.pop();

		// wait가 비었다면 ing에서 pop 작업만 해주면 됨
		if (wait.empty()) {
			answer++; 
			continue;
		}

		// wait 큐의 front 값과 현재 도로 위 트럭의 무게를 합쳤을 때
		// 다리가 감당할 수 있는 무게보다 크다면 0을 ing 큐에 push
		if (t_weight + wait.front() > weight) {
			ing.push(0);
		}
		else { // 아니라면 wait 큐의 front 값을 push하고 wait 큐 pop
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