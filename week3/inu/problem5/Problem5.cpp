#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<>> pq;
    for (int i : scoville)
        pq.push(i);

    while (true) {
        if (pq.size() < 2) {
            break;
        }

        if (pq.top() >= K)
            break;
        
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        int c = a + (b * 2);
        pq.push(c);

        answer++;
    }

    if (pq.top() < K)
        answer = -1;

    return answer;
}

int main() {
    vector<int> scoville = { 1, 2, 3, 9, 10, 12 };
    int K = 100;
    cout << solution(scoville, K);
}