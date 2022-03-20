#include<iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX = 1001;
vector<int> adj[MAX];
int pred[MAX];
queue<int> q;
int result[MAX];

int main(void) {
	int N, M;
	cin >> N >> M;

    int a, b;
    //인접 리스트 생성과 함께 pred라는 노드 기준 내 조상이 얼마나 달려있는지 를 초기화.
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        pred[b]++;
    }

    // 초기 queue 생성 : 내 조상이 없으면 push
    for (int i = 1; i <= N; i++) {
        if (pred[i] == 0) {
            q.push(i);
        }
        result[i] = 1; //1학기부터 시작(초기화)
    }

    while (!q.empty()) {
        //큐를 비우면서
        int cur = q.front();
        q.pop();

        for (int i = 0; i < adj[cur].size(); i++) {
            int next = adj[cur][i];
            pred[next]--;
            if (pred[next] == 0) {
                q.push(next);
                result[next] = result[cur] + 1;                
                //result[next] = max(result[next], result[cur] + 1); 
                //왜 max로 하는지 헷갈, 그냥 수정으로 해주면 안되나? 
                //점점 사이즈 커지면서 크게 설정 될거 같은데(되네)
                //많은곳에서 이렇게 해뒀던데 이유를 모르겠음
            }
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << result[i] << " ";
    }

    return 0;
}

//https://www.acmicpc.net/problem/14567
//14567 선수과목
//https://scarlettb.tistory.com/118#:~:text=3%EA%B0%9C%EC%9D%98%20%EA%B3%BC%EB%AA%A9%EC%9D%B4%20%EC%9E%88%EA%B3%A0,%EA%B3%BC%EB%AA%A9%EC%9D%84%20%EC%9D%B4%EC%88%98%ED%95%B4%EC%95%BC%20%ED%95%9C%EB%8B%A4.&text=%EC%9C%84%EC%83%81%20%EC%A0%95%EB%A0%AC%ED%95%98%EB%A9%B4%EC%84%9C%20%EC%B6%9C%EB%A0%A5%20%EB%B0%B0%EC%97%B4,%ED%95%99%EA%B8%B0%20%EC%88%98%EB%A5%BC%20%EC%A0%80%EC%9E%A5%ED%95%9C%EB%8B%A4.

