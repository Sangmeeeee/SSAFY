#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer;
    int weight_sum = 0;
    vector<int> pos(truck_weights.size(), 0);
    queue<int> q;

    q.push(0);
    weight_sum = truck_weights[0];
    pos[0] = 1;
    answer = 1;

    while (q.size() != 0) {
        // 앞으로 이동
        int front = q.front(), back = q.back();
        for (int i = front; i <= back; i++)
            pos[i]++;

        if (pos[front] > bridge_length) {
            weight_sum -= truck_weights[front];
            q.pop();
        }

        back++;
        // 다리 위로 트럭 이동
        if (q.size() < bridge_length &&
            weight_sum + truck_weights[back] <= weight) {
            q.push(back);
            weight_sum += truck_weights[back];
            pos[back]++;
        }

        answer++;
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int bridge_length;
    int weight;
    int num;
    vector<int> truck_weights;

    cin >> bridge_length;
    cin >> weight;
    cin >> num;
    for (int i = 0; i < num; i++) {
        int n;
        cin >> n;
        truck_weights.push_back(n);
    }

    cout << solution(bridge_length, weight, truck_weights);

    return 0;
}