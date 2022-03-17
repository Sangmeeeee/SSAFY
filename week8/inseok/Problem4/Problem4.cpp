#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>

using namespace std;

int main(void) {
	vector<int>adj[10002];
	int N;
	vector<int>weight;
	int K;
	vector<int>isDeg;
	int maxT=0;
	vector<int>result;
	//input firstLine
	cin >> N;
	//init
	weight = vector<int>(N+1);
	isDeg = vector<int>(N+1); 
	result = vector<int>(N+1);

	//input 
	for (int i = 1; i <= N; i++) {
		//input w
		cin >> weight[i];
		result[i] = weight[i];
		//input K
		cin >> K;
		//input p(k 보다 빠른 p들)
		//adjList 만들기
		for (int j = 0; j < K; j++) {
			int pre;
			cin >> pre;
			adj[pre].push_back(i);
		}
		isDeg[i] = K; //isDeg 가 무슨 줄임말일까?난 pred(predecessor)이런거 쓰고 싶은데	..	
	}
	
	//queue 초기화
	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (isDeg[i] == 0) {
			q.push(i);
			//adj 리스트 뺴기 를 할 필요 가 없구나.. 뒤에서 isDeg를 보면 되겠네.
			//maxT갱신
			maxT = max(weight[i], maxT);
		}
	}
	
	//sol
	while (!q.empty()) {
		//큐를 비우면서
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			//간선 제거
			isDeg[next]--;
			//result 수정
			result[next] = max(result[cur] + weight[next], result[next]);//이거 위치 여기구나..
			//간선 아예 없으면 next 도 이제 넣어줘야
			if (isDeg[next] == 0) {
				q.push(next);
				
				maxT = max(result[next], maxT);
			}
		}
	}
	cout << maxT;

	return 0;
}