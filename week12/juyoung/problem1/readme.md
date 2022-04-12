# Info

문제 : [타임머신](https://www.acmicpc.net/problem/11657)

알고리즘 종류 : 벨만포드

참조 url : 


# 1. 알고리즘 설명

벨만포드 알고리즘으로 풀 수 있다.

:rose:  
하나의 벡터에 모든 간선을 입력 받고 최단 거리 배열 **`dist`를 무한대로 초기화**한다.

:rose:  
시작 노드의 최단 거리를 0으로 초기화한 후 **모든 간선에 대해 최단 거리를 갱신**한다.  
이를 **N-1번 반복하고 난 후, 한 번 더 수행**한다.   
이때 업데이트 되는 정점이 있다면 음수 사이클이 존재한다는 의미이다.  
즉, 문제대로 해석하자면 시간을 무한히 오래 전으로 되돌릴 수 있다는 뜻이다.  

:rose:  
음수 사이클이 존재하는 경우 -1을 출력하고 프로그램을 종료한다.  
그렇지 않으면 시작 노드를 제외한 노드들의 최단 거리를 차례대로 출력한다.


# 2. 새로 배운 내용(코드 위주)
## 벨만-포드(Bellman-Ford) 알고리즘
다익스트라와 마찬가지로 한 노드에서 다른 노드까지의 최단 거리를 구하는 알고리즘이다.

### 다익스트라 vs 벨만포드
**다익스트라**
- 매번 방문하지 않은 노드 중 cost가 가장 작은 노드를 선택한다.
- 음수 간선이 있다면 최적의 해를 찾을 수 없다.
- 시간 복잡도 `O(ElogV)` (우선순위 큐 사용 시)

**벨만포드** 
- 매번 모든 간선을 전부 확인한다는 차이점이 있다.  
- 음수 간선이 있어도 최적의 해를 찾을 수 있다.  
	- 음수 간선의 cycle을 감지할 수 있기 때문이다.
- 시간 복잡도 `O(VE)`

### 알고리즘 수행 과정
1. 출발 노드를 설정한다.
2. 최단 거리 테이블을 무한대로 초기화한다.
3. 다음 과정을 V-1번 반복한다. (V=정점 개수)
	1. 모든 간선 E개를 하나씩 확인한다.
	2. 각 간선을 거쳐 다른 노드로 가는 비용을 계산하여 최단 거리 테이블을 갱신한다.

음수 간선 cycle이 존재하면 최단 거리를 무한히 줄일 수 있게 된다.  
이러한 cycle의 발생 여부를 체크하려면 3번 과정을 한 번 더 수행한다.  
이때 최단 거리 테이블이 갱신된다면 음수 간선 cycle이 존재하는 것이다.

### 코드
```cpp
void bellmanford() {
	dist[1] = 0;
	for(int i=1; i<=N-1; i++) {
		for(int j=0; j<edge.size(); j++) {
			int from = edge[j].first.first;
			int to = edge[j].first.second;
			int cost = edge[j].second;

			if(dist[from] == INF) continue;
			if(dist[to] > dist[from] + cost) dist[to] = dist[from] + cost;
		}
		
		for(int i=0; i<edge.size(); i++) {
			int from = edge[i].first.first;
			int to = edge[i].first.second;
			int cost = edge[i].second;

			if(dist[from] == INF) continue;
			if(dist[to] > dist[from] + cost) {
				cout << "음의 사이클 존재"
				return;
			}
		}
	}
}
```
