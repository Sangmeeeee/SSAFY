# Info

문제 : [골목길](https://www.acmicpc.net/problem/1738)

알고리즘 종류 : 벨만포드

참조 url : https://imnotabear.tistory.com/158


# 1. 알고리즘 설명

하.... 계속 틀리길래 코드가 잘못된 줄 알고 몇 번이나 코드를 바꿨는데  
알고보니 `memset()` 사용을 잘못해서 배열이 제대로 초기화가 안되고 있었던 거였다...  

아무튼 벨만포드와 BFS를 이용하여 풀었다.  
처음엔 음수 사이클 여부로만 문제를 풀다가 잘 모르겠어서 다른 분 코드를 참고했다.  

:bear: **접근**  
문제에서 구하고자 하는 것은 *금품의 양의 최대가 되는 경로*이다.  
따라서 최단 경로가 아닌 최장 경로를 찾아야 하는데,  
굳이 그럴 필요 없이 입력 받는 cost에 모두 `*-1`을 취하고 최단 경로를 찾아주면 된다.

또한 문제에서 *최적의 경로를 구할 수 없는 경우*는 다음의 두 가지이다.
1. **출발지에서 도착지로 가는 경로가 아예 없는 경우**  
2. **도착지로 가는 경로에 음수 사이클이 존재하는 경우**  

이때 중요한 것은 그냥 음수 사이클이 존재하는 경우가 아니라  
*도착지로 가는 경로에* 음수 사이클이 존재하는 경우, 최적의 경로를 구할 수 없다는 것이다.  
그 외에 사이클이 없는 모든 경우는 최적의 경로를 구할 수 있다.

:bear: **입력**  
앞서 말했듯이 cost를 `-cost` 상태로 배열에 저장한다.

:bear: **알고리즘**  
우선 벨만포드 알고리즘을 사용하여 최단 거리 및 음수 사이클 여부를 구해야 한다.  
나는 기존에 벨만포드 알고리즘을 작성할 때 모든 간선에 대해 `n-1`번 탐색한 후  
또 다른 for문을 작성하여 한번 더 모든 간선에 대해 탐색하게 했었다.  
그러나 이번에는 처음부터 `n`번을 탐색하도록 설정하고, `n`번째 탐색일 때만 사이클 여부를 판단하도록 했다.

노드의 최단 거리 값에 변화가 있으면서 `n`번째 탐색이라면 해당 노드는 사이클에 포함되는 노드이다.  
이때 해당 노드를 출발로 하는 bfs를 수행하여 그 노드가 도착지와 연결된 노드인지를 판단한다.  
`visited` 함수에 연결된 노드들의 방문 여부를 저장하고, `visited[n]`이 `true`라면  
도착지로 가는 경로에 음수 사이클이 존재함을 알 수 있다.  
이 경우 `cycle` 변수를 `true`로 만들고 `bellmanford()` 함수를 종료했다.

만약 최단 거리 값에 변화가 있으나 `n`번째 탐색이 아니라면 경로 출력을 위해 `parent` 배열에 노드들의 부모를 저장해준다.  

:bear: **출력**  
위에서 언급한 *최적의 경로를 구할 수 없는 경우*에는 `-1`를 출력한다.  
1. `dist[n]`가 `INF`인 경우 (업데이트 되지 않은 경우)  
2. `cycle`이 `true`인 경우 (음수 사이클이 존재하는 경우)  

만약 음수 사이클이 존재하지 않는다면!  
`parent` 배열에 저장해둔 부모 노드를 거슬러 올라가며 새로운 벡터에 경로를 저장하고, 이를 거꾸로 출력한다.


# 2. 새로 배운 내용(코드 위주)