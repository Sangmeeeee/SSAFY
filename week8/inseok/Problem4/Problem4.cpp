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
		//input p(k ���� ���� p��)
		//adjList �����
		for (int j = 0; j < K; j++) {
			int pre;
			cin >> pre;
			adj[pre].push_back(i);
		}
		isDeg[i] = K; //isDeg �� ���� ���Ӹ��ϱ�?�� pred(predecessor)�̷��� ���� ������	..	
	}
	
	//queue �ʱ�ȭ
	queue<int>q;
	for (int i = 1; i <= N; i++) {
		if (isDeg[i] == 0) {
			q.push(i);
			//adj ����Ʈ ���� �� �� �ʿ� �� ������.. �ڿ��� isDeg�� ���� �ǰڳ�.
			//maxT����
			maxT = max(weight[i], maxT);
		}
	}
	
	//sol
	while (!q.empty()) {
		//ť�� ���鼭
		int cur = q.front();
		q.pop();
		for (int i = 0; i < adj[cur].size(); i++) {
			int next = adj[cur][i];
			//���� ����
			isDeg[next]--;
			//result ����
			result[next] = max(result[cur] + weight[next], result[next]);//�̰� ��ġ ���ⱸ��..
			//���� �ƿ� ������ next �� ���� �־����
			if (isDeg[next] == 0) {
				q.push(next);
				
				maxT = max(result[next], maxT);
			}
		}
	}
	cout << maxT;

	return 0;
}