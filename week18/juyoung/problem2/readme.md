# Info

문제 : [n진수 게임](https://programmers.co.kr/learn/courses/30/lessons/17687)

알고리즘 종류 : 

참조 url : 


# 1. 알고리즘 설명

미리 구할 숫자 `t`개를 다 구할 때까지 문자열 `number`에 `n`진법의 수를 0부터 차례로 추가하고,  
여기서 튜브의 순서에 맞는 수를 `answer` 문자열에 추가하여 문제를 풀었다.

`answer`에 튜브가 미리 말할 숫자를 넣기 때문에 `answer`의 길이가 `t`가 될 때까지 아래 과정을 반복했다.  
(`num`은 0으로 초기화하고 시작한다.)

1. `change()` 함수를 통해 현재 숫자 `num`을 `n`진법으로 표현한 문자열을 반환받는다.
2. 반환받은 문자열을 `number` 문자열 뒤에 추가한다.  
3. `(num+1)%m`이 `p`라면, 즉 튜브의 차례라면 `answer`에 `number[num]`을 추가한다.
	- 만약 `m`과 `p`가 같다면 `(num+1)%m`이 0일 때 튜브의 순서가 되기 때문에 이 부분은 따로 처리한다.
4. `num`을 1 증가시킨다.


# 2. 새로 배운 내용(코드 위주)
