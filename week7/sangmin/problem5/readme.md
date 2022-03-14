문제 : [행렬 제곱](https://www.acmicpc.net/problem/10830)

알고리즘 종류 : 분할정복

참조 url : 

# 1. 알고리즘 설명

A(N)을 N번째 행렬의 제곱이라고 했을 때, A(N)은 A(N / 2) * A(N / 2)가 된다.

A(1)에서 부터 N까지 차근차근 올라가면 반드시 시간초과가 나온다.

따라서 N을 2씩 나누어주면서 연산을 진행해준다.

A(N) = A(N / 2) * A(N / 2)에서 A(2) = A(1) * A(1)까지 연산을 재귀적으로 호출해주는데

만약 A(N)에서 N이 홀수일 경우 A(N - 1)을 구한 뒤, A(1)을 곱해준다.

이렇게되면 시간 복잡도는 logN이 나온다.

# 2. 새로 배운 내용