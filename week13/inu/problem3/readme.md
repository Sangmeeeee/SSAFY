# Info

  

문제 : [세부](https://www.acmicpc.net/problem/13905)

알고리즘 종류 : 분리집합, MST

참조 url : [여기](https://www.acmicpc.net/board/view/10880)

  

# 알고리즘 설명
이 문제에서는 최대한 많은 금빼빼로를 가져가는 것이 목표이기 때문에 간선의 가중치를 기준으로 내림차순 정렬을 해야 한다.  
- 이 때 간선을 배열에 담아서 sort로 정렬하는 방법과 우선순위 큐로 정렬하는 방법 2가지가 있다.

그 후에 차례대로 간선을 스패닝 트리에 추가해보면서 시작점과 도착점이 연결되었는지 확인한다.  
현재 간선을 스패닝 트리에 추가함으로써 시작점과 도착점이 연결되었다면 해당 간선의 가중치가 최대 금빼빼로 수가 된다.
 ```c++
 for (edge e : graph) {
	// 이미 연결되어 있으면 패스
	if (Find(e.u, e.u) == Find(e.v, e.v))
		continue;
	// 아니면 연결
	Union(e.u, e.v);
	// 간선을 추가해서 시작점과 도착지가 연결되었을 때
	if (Find(S, S) == Find(E, E)) {
		cout << e.w;
		return 0;
	}
}
 ```

# 새로 배운 내용
우선순위 큐를 생성할 때 compare 구조체를 넘겨서 정렬 조건을 명시할 수 있다.  
구조체는 다음과 같은 형식을 가진다.
```c++
struct compare {
	bool operator()(edge& e1, edge& e2) {
		return e1.w < e2.w;
	}
};
priority_queue<edge, vector<edge>, compare> pq;
```
algorithm 헤더파일에 있는 sort()에서 compare를 정의할 때 e1.w가 e2.w보다 작도록 만든다는 뜻이므로 오름차순 정렬이 된다.  
그러나 우선순위 큐에서는 e1.w < e2.w이면 swap을 한다는 뜻이므로 내림차순 정렬이 된다.