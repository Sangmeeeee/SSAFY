# Info

문제 : [연산자 끼워넣기 (3)](https://www.acmicpc.net/problem/15659)

알고리즘 종류 : 스택, 문자열, 백트래킹

참조 url : 없음

# 알고리즘 설명
1. 문제를 크게 보면 연산자의 조합을 구해야하는 문제이다.
2. 조합을 구하기위해 백트래킹을 이용했다.
3. 연산자의 수는 제한되어 있기 때문에 사용 가능한지 체크를 해줘야 한다. 그래서 사용을 했다면 -1을 해준다.
4. 백트래킹으로 연산자의 조합이 구해지면 calculation 함수에서 식의 계산을 해준다.
5. 연산자의 조합과 수열을 합쳐준 후 연산자 우선 순위를 이용해 계산을 해야하므로 내장 함수 eval()로 수식을 계산해준다.
6. 결과를 return 해주고 조합마다 최솟값, 최댓값을 구해준 후 출력해준다.


# 새로 배운 내용