# Info

  

문제 : [두 동전](https://www.acmicpc.net/problem/16197)

알고리즘 종류 : 백트래킹

참조 url :

  

# 알고리즘 설명
두 동전을 상하좌우에 대해 모두 움직여보면서 백트래킹으로 최소 이동횟수를 찾는다.  
이 때 총 4가지의 종료 조건이 있다.
1. 두 동전이 모두 떨어지는 경우
2. 두 동전이 모두 벽에 막힌 경우
3. 두 동전 중 하나만 떨어진 경우
4. 이동횟수가 최소값보다 크거나 10보다 큰 경우  

1, 2, 4번은 그냥 종료하면 되고 3번은 최소값을 갱신하고 종료한다.  
이 외에는 동전을 다음 위치로 이동시키면 된다.
# 새로 배운 내용