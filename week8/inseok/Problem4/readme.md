문제:  [작업](https://www.acmicpc.net/problem/2056)

알고리즘 종류 : 위상정렬(Topological Sort)

참조 url : [https://gmlwjd9405.github.io/2018/08/27/algorithm-topological-sort.html](https://gmlwjd9405.github.io/2018/08/27/algorithm-topological-sort.html)

# 1. 알고리즘 설명(로직위주)

## 문제 이해

오랜만에 C++ 로 해서 그런지 헷갈리더라.

그리고 학교에서 Topological Sort 왜 배운 기억이 없지... 첨 보는 느낌이라서 공부 하느라 애먹었다 다익스트라 급으로 느껴졌음.

## Topological Sort

### Topological Sort 란

- 방향이 존재 하는 그래프에서
- 각 정점 들에 선행 순서가 존재하여

이를 지키면서 정점 들을 나열 하는 것이다.

### 어떻게 풀어야 하나?(알고리즘)

1. 초기화
    - 정점과 간선을 삽입 (인접 리스트)
    - 간선의 수를 초기화(array 이용)
    - queue를 만들어서 들어오는 녀석이 없는 (진입 차수(degree)가 0인) 정점들을 모두 queue에 삽입. 이때 들어오는 순서는 무방, 모든 순서가 정렬 가능하다.
2. sort
    - queue에서 빠진 정점을 현재 정점으로 두고
    - 현재 정점에서 연결된 모든 간선에 대해 간선의 수를 감소 시켜 준다 (미리 간선의 수를 초기화 하였기에 간선 찾는데 시간 복잡도 O(1))
    - 

### 어떨때 써야할까?

뭐 그래프, 선행 조건 존재 이럴 때 써야겠다. 

익숙 하지가 않아서 이런 문제들을 이번에 익혔으니 저런 문제가 나왔을때 다시 한번더 풀어봐야겠다.

## 로직

위의 방법으로 문제를 풀었고 여기에서 특별 했던건 가중치가 있는 상황에서 시간을 구해줬어야 했다. result라는 시간 array를 만들었고, weight라는 가중치 array를 만들어서 이를 최신화 해주면서 문제를 풀었다.

# 2. 새로 배운 내용(코드위주)