# Info

문제 : [로봇 청소기](https://www.acmicpc.net/problem/14503)

알고리즘 종류 : 구현, 시뮬레이션

참조 url : 없음

# 알고리즘 설명

while문으로 계속해서 시뮬레이션이 실행되도록 해줬다.

1. 현재 위치가 청소를 할 수 있는 곳이라면 청소 처리를 해주고 청소하는 영역의 개수를 +1 더해준다.
2. 네 방향 모두가 청소가 이미 되어있거나 벽인 경우를 변수 cnt로 확인해주며 연속해서 네 방향 모두가 청소 or 벽이라면 한 칸 후진을 해준다. 만약 한 칸 후진도 할 수 없으면 청소하는 영역의 개수를 저장한 변수를 print 해준다. 그렇지 않다면 후진한 위치와 변수 cnt를 0으로 초기화하여 계속해서 시뮬레이션을 실행한다.
3. 현재 방향에서 왼쪽 방향을 계속해서 탐색하며 청소하지 않은 공간이 존재하면 그 방향으로 회전한 다음 한 칸을 전진하도록 하고 그렇지 않다면 변수 cnt에 +1을 더해준다. 그리고 방향을 왼쪽으로 틀어준다.

# 새로 배운 내용