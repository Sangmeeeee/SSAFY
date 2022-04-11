# Info

문제 : [텔레포트](https://www.acmicpc.net/problem/16958)

알고리즘 종류 : 플로이드 와샬

참조 url : 없음

# 알고리즘 설명

1. 도시의 정보를 2차원 배열 city에 입력받는다.
2. 2중 for문을 이용하여 i->j로 가는 비용을 구해준다. 만약 특별한 도시라면 graph[i][j] = Math.min(graph[i][j],t)로 최소 비용을 구해준다.
3. 플로이드 와샬 알고리즘
    - i에서 j로 갈 때, k를 거쳐서 가는 경우가 더 짧을 경우 해당 값으로 업데이트
4. 각 다른 도시 사이의 최소 비용을 출력.

# 새로 배운 내용