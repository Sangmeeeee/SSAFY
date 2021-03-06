# Info

문제 : [연산자 끼워넣기 (3)](https://www.acmicpc.net/problem/15659)

알고리즘 종류 : 백트래킹, 스택

참조 url :


# 1. 알고리즘 설명

알고리즘 분류는 스택이었지만 **백트래킹**과 **벡터**를 사용하였다.

1. 크기 4만큼의 int형 배열에 연산자의 개수를 저장하고 백트래킹 시 for문을 돌려 각 인덱스의 값이 0보다 크다면 1만큼 줄이고, 벡터에 해당 연산자를 저장한다.
2. 백트래킹 함수를 재귀적으로 호출하며 전체 연산자의 개수와 벡터의 크기가 같아지면, 벡터에 저장된 연산자 순서를 바탕으로 연산한다.
	1. 연산 시 곱셈, 나눗셈을 먼저 처리하고 덧셈, 뺄셈을 처리한다.
	2. 연산 시 새로운 벡터 2개를 선언하여 하나는 피연산자로, 나머지 하나는  백트래킹을 돌며 저장한 연산자 순서로 초기화하여 연산이 완료된 부분은 지우며(`erase()`) 진행한다.
3. 연산이 끝나면 피연산자로 초기화했던 벡터의 0번째 인덱스에는 연산 결과가 저장되며, 이를 바탕으로 최댓값/최솟값을 업데이트한다.


# 2. 새로 배운 내용(코드 위주)
