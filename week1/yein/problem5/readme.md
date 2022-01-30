# Info

문제 : [괄호 회전하기](https://programmers.co.kr/learn/courses/30/lessons/76502)

알고리즘 종류 : 문자열, 스택

참조 url : 없음

# 알고리즘 설명
1. dictionary를 사용하여 예를들어 key 값이 ')' 이면 '('을 반환할 수 있도록 해준다.


2. while문으로 cnt<len(s) 동안 문자열 s의 길이만큼 반복해준다.


3. 배열 변수인 stack을 선언해주고 문자 s를 탐색하며 괄호의 시작 문자가 나오면 stack에 append 해준다.


4. 괄호가 끝나는 문자가 나오면 우선 stack이 비어있는지 확인하고, stack이 비어있지 않고 stack의 마지막 문자와 pair면 stack을 pop해준다.


5. 그리고 stack이 비었다면 bool 변수인 check를 false 처리하고 for문을 break 시켜준다.


6. for문으로 문자열 s의 탐색이 끝날 때 마다 check가 true이고 stack이 비어있다면 answer값을 +1 해준다.


7. cnt를 +1 증가시켜주고 s = s[1:] + s[0] 을 해준다. ---> 앞의 문자가 뒤로 가도록


# 새로 배운 내용
