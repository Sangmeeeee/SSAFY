문제 : [캠프 준비](https://www.acmicpc.net/problem/16938)

알고리즘 종류 : dfs, 백트래킹

참조 url : 

# 1. 알고리즘 설명

dfs를 통해 문제를 포함 했냐, 안했냐의 판단을 통해 부분집합을 구한다.

이 때, 부분집합의 총 합이 R보다 크면 dfs를 더이상 진행하지 않는다.

dfs를 진행하면서 만약 부분집합의 크기가 2보다 크다면 문제의 요구조건인

1. R보다 작거나 같다
2. C보다 크거나 같다
3. max - min은 X보다 크거나 같다.

를 만족하는 부분집합일 경우 count를 + 1 해준다.

# 2. 새로 배운 내용

