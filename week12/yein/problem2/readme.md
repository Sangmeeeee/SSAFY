# Info

문제 : [웜홀](https://www.acmicpc.net/problem/1865)

알고리즘 종류 : 벨만 포드

참조 url : 없음

# 알고리즘 설명
1. 최단 거리 테이블을 초기화 시킨다.
2. 인접리스트 방식으로 양방향으로 입력을 받는다.
3. 웜홀 구간은 음수로 입력 받는다.
4. 벨만 포드를 활용하여 dist[node] > dist[j] + cost 인 경우 값을 갱신해주고 i==n 일 때도 갱신이 된다면 true를 return 해준다. 그렇지 않은 경우는 false를 return해준다.
5. return 값에 따라 YES 인지 NO 인지 출력해준다.

# 새로 배운 내용
