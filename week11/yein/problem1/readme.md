# Info

문제 : [플로이드](https://www.acmicpc.net/problem/11404)

알고리즘 종류 : 플로이드 와샬

참조 url : 없음

# 알고리즘 설명

1. 도시의 개수 n과 버스의 개수 m을 입력받는다.
2. 초기 비용을 int(1e9)로 초기화 시켜준다.
3. 자기 자신으로 가는 노드는 비용을 0으로 설정해준다.
4. 버스의 시작 도시와 도착 도시를 입력받으며 a->b로 가는 비용을 graph[a][b]=min(graph[a][b],c)로 저장해준다.
5. a->b로 가는 최소 비용을 플로이드 와샬로 3중 for문을 이용하여 graph[a][b]의 최솟값을 구해준다.
6. int(1e9)가 아닌 값만 출력해준다.

# 새로 배운 내용
