# Info

문제 : [최소비용 구하기](https://www.acmicpc.net/problem/1916)

알고리즘 종류 : 다익스트라

참조 url : 


# 1. 알고리즘 설명

다익스트라 알고리즘을 적용하되 가지치기가 필요한 문제였다.  
그리고 그래프를 만들 때 양방향이 아니라 **단방향**임에 주의해야 했다.

다익스트라 알고리즘을 수행할 때  
우선순위 큐에서 꺼낸 노드가 이미 최단 경로를 체크한 노드인 경우,  
해당 노드와 인접한 노드들을 탐색하지 않고 `continue` 해줘야 한다.  
그렇지 않으면 시간 초과가 발생한다.


# 2. 새로 배운 내용(코드 위주)
