# Info

  

문제 : [타임머신](https://www.acmicpc.net/problem/11657)

알고리즘 종류 : 벨만포드

참조 url : 

  

# 알고리즘 설명
기본적인 벨만포드 알고리즘 문제이다.  
- 음수 사이클 판단
    - 그래프에 음수 사이클이 있다고 해서 무조건 -1을 출력하는 것이 아니라 시작점에서 음수 사이클을 이루는 정점에 도달 가능할 때만 음수 사이클이 있다고 판별하는 것이다.  
    - 모든 간선에 대한 완화 작업을 할 때, 시작점에서 w(u, v)의 u에 도달 가능할 때만(즉, upper[u] != INF일 때만) 완화를 시도해야 하고 도달할 수 없다면 완화를 시도해볼 필요가 없다. 
    - 정점이 V개인 그래프의 최단 경로는 최대 (V - 1)개의 간선을 가질 수 있다. 그래서 모든 간선에 대한 완화 작업을 (V - 1)번 반복하면 되는데 이 작업을 한번 더 해서 성공하면 음수 사이클이 있는 것이고 실패하면 음수 사이클이 없는 것이다.  
    - 음수 사이클이 있을 때는 벡터를 비우고 반환해서 함수를 호출한 곳에서 음수 사이클 여부를 알 수 있게 한다.
```c++
vector<long long> bellmanFord(int src) {
	vector<long long> upper(N + 1, INF);
	upper[src] = 0;
	bool success;

	// 모든 간선에 대한 완화 작업을 N번 반복한다.
	for (int iter = 0; iter < N; iter++) {
		success = false;
		for (int u = 1; u <= N; u++) {
			// 시작점에서 도달할 수 없는 정점이면 그냥 넘김
			if (upper[u] == INF)
				continue;
			for (int cur = 0; cur < (int)graph[u].size(); cur++) {
				int v = graph[u][cur].first;
				int cost = graph[u][cur].second;				
				// 간선 (u, v)에 대한 완화 시도
				if (upper[v] > upper[u] + cost) {
					// 완화 성공
					upper[v] = upper[u] + cost;
					success = true;
				}
			}
		}
		// 모든 간선에 대해 완화가 실패했으면 반복문 종료
		if (!success) break;
	}
	// 마지막 N번째 완화 작업도 성공하면 음수 사이클이 있는 것
	if (success) upper.clear();
	return upper;
}
```

만약 N=500, M=6000이고 모든 간선이 1 -> 2, 2 -> 1로만 이루어져 있으며 그 가중치가 10000 또는 -10000일 때 int형으로 계산을 하면 overflow, underflow가 발생한다. 따라서 최단 거리를 저장하는 벡터의 자료형을 long long으로 해주어야 한다.


# 새로 배운 내용
