# Info

문제 : [오민식의 고민](https://www.acmicpc.net/problem/1219)

알고리즘 종류 : 벨만포드

참조 url : 


# 1. 알고리즘 설명

백준 1738 골목길 문제와 비슷하게 벨만포드와 BFS로 접근할 수 있는 문제였다.


:bear: **주의해야 할 점**  
우선 문제에서 주의해야 할 점은 두 가지 정도 있었다.

첫째, **교통 수단의 가격은 최대 1,000,000이다.**  
사이클이 도는 것을 고려하여 최대 액수를 저장하는 배열 `dist`을 long 타입으로 선언했다.

둘째, **오민식이 도착 도시에 도착했을 때 돈을 무한히 많이 가지는 경우**는  
출발지에서 도착지로 가는 경로 사이에 사이클이 존재하는 경우이다.  
모든 경로를 통 틀어서 사이클의 여부를 판단하면 안된다.

아래가 그래프 자체에는 사이클이 존재하지만  
출발지와 도착지 사이에는 사이클이 존재하지 않는 예제이다.
![KakaoTalk_20220415_214430839](https://user-images.githubusercontent.com/57346428/163587669-21774490-0ffb-4ed2-9c54-17716ff2793d.jpg)


:bear: **입력**  
문제에 따르면 어떤 도시로 갈 때마다 드는 교통비와 해당 도시에서 벌 수 있는 돈이 있다.  
문제에서는 최대 액수를 구하라고 했는데, 벨만포드는 최단 거리를 구하는 알고리즘이므로  
도시로 이동하는 데 필요한 *교통비를 양수로* 입력 받고  
벨만포드를 수행 시 어떤 도시로 이동하면 *그 도시에서 버는 돈을 감소*시켰다.


:bear: **알고리즘**  
1. 초기화
	- 최단 비용 `dist` 배열을 전부 무한대로 초기화한다.
	- 출발지 `A`에 대해서만 A 도시에서 벌 수 있는 돈 * -1 한 값으로 초기화한다.
2. 벨만포드 알고리즘 + BFS
	- `n`번째 탐색할 때 어떤 도시에 대해 최단 비용이 갱신된다면 해당 간선의 출발 노드를 시작으로 bfs를 돌린다.
	- bfs 수행 시 방문된 노드들은 `visited` 배열을 `true`로 갱신한다.
	= 만약 도착지 `B`에 대해 `visited[B]`가 `true`라면 `cycle`에  `true`를 저장한다.  


:bear: **출력**  
아예 출발지에서 도착지로 갈 수 없는 경우.  
즉 `dist[B]`가 한 번도 업데이트되지 않아서 값이 `INF`인 경우 `gg`를 출력한다.

출발지에서 도착지로 가는 경로에 사이클이 존재한다면 `Gee`를 출력한다.

그 외에는 도착지에 저장된 최대 액수를 출력한다.  
이때 우리는 교통비에 대해 +하고 번 돈에 대해 -를 했기 때문에 `-dist[B]` 값을 출력해야 한다.



# 2. 새로 배운 내용(코드 위주)
