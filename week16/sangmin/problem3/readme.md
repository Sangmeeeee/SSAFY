문제 : [수식 최대화](https://programmers.co.kr/learn/courses/30/lessons/67257)

알고리즘 종류 : 스택, 구현

참조 url :

# 1. 알고리즘 설명

중위 표현식을 후위 표현식으로 변경한 후 후위 연산을 해주어야 한다.

한가지 특이한 부분은 +, -, * 연산자의 우선순위를 각각 지정한 케이스마다 절대값을 구하고

절대값이 큰 경우를 정답으로 해주어야한다.

따라서 문자열 "+-*"와 orders 배열을 이용한다.

"+-*" 문자열에서 indexOf 메소드를 이용해서 '+'의 index를 찾으면 0이 나온다.

orders의 배열이 만약 {0, 1, 2}라면 '+'의 우선순위는 0번째, '-'의 우선순위는 1번째, '*'의 우선순위는 2번째이다.

orders의 배열이 만약 {2, 0, 1}이라면 '+'의 우선순위는 2번째, '-'의 우선순위는 0번째, '*'의 우선순위는 1번째이다.

# 2. 새로 배운 내용