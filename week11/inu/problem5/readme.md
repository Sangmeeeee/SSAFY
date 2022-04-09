# Info

  

문제 : [궁금한 민호](https://www.acmicpc.net/problem/1507)

알고리즘 종류 : 플로이드-와샬

참조 url : 

  

# 알고리즘 설명
주어진 간선 일부를 제거해도 최단 거리를 유지할 수 있는지 확인하고 제거된 후의 간선 가중치합을 구하는 문제이다.  
```c++
bool floyd() {
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (k != i && i != j && k != j) {
					if (graph[i][k] + graph[k][j] < graph[i][j]) {
						if (graph[i][j] == INF)
							continue;
						return false;
					}
					else if (graph[i][k] + graph[k][j] == graph[i][j])
						graph[i][j] = INF;
				}
			}
		}
	}			
	return true;
}
```

- k를 거쳐서 i에서 j로 가는 경로 길이가 그냥 i에서 j로 가는 경로 길이와 같다면 i, j를 연결하는 간선이 없어도 된다는 뜻이다. 이와 같은 조건을 만족하면 해당 간선 가중치를 미리 설정해둔 INF로 해서 없는 간선으로 간주한다.
- i에서 j로 가는 경로가 갱신된다면 주어진 입력값이 최단 경로라는 전제에 모순되므로 false를 반환해서 -1을 출력한다.
- true를 반환하면 간선 가중치가 INF가 아닌 것만 다 더해서 출력하면 된다.


# 새로 배운 내용
