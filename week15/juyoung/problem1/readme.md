# Info

문제 : [문자열압축](https://programmers.co.kr/learn/courses/30/lessons/60057)

알고리즘 종류 : 

참조 url :


# 1. 알고리즘 설명

자를 문자의 개수를 1부터 주어진 문자열의 길이의 절반까지 늘리며  
각 개수에 따른 압축 문자열을 구하고, 문자열 중 가장 길이가 짧은 문자열의 길이를 반환한다.  

자를 문자의 개수 `len`이 주어진 문자열 `s`의 길이의 절반보다 작거나 같은동안 아래의 과정을 수행한다.  
1. `s`의 처음부터 `len`개만큼 잘라낸 문자열을 `temp`에 저장한다.
2. for문을 통해 문자열 `s`를 탐색한다. 이때 인덱스 `len`부터 시작하며 매번 `len`만큼 증가한다.
	1. `temp`와 현재 인덱스부터 `len`만큼 잘라낸 문자열이 같다면 `cnt`를 증가시킨다.
		- 이때 `cnt`는 `temp`로 압축할 수 있는 개수를 뜻한다.
	2. 그렇지 않다면
		1. `temp`의 압축 개수와 `temp`를 `ans_str`이라는 변수에 문자 형태로 붙인다.
		2. 현재 위치에서 다시 `len`만큼 자른 문자열을 `temp`에 저장하고 `cnt`도 1로 초기화한다.
3. `ans_str`에 마지막 `temp`를 합친다.
	- for문은 마지막 `temp`가 `ans_str`에 합쳐지지 않은 채로 종료되기 때문이다.
	- 이때, `cnt`가 1보다 큰 상태라면 `cnt` 또한 `temp`와 함께 `ans_str`에 문자 형태로 합친다.
4. 현재 `answer`보다 `ans_str`의 길이가 작다면, `ans_str`의 길이를 `answer`에 저장한다.
	- `answer`에는 현재까지 압축한 문자열 중 가장 길이가 짧은 문자열의 길이가 저장되어 있다.
5. `len`을 1만큼 늘리고 while문을 반복한다.


`aaaabbcd`에 대한 압축 문자열을 구할 때, `len`이 2인 경우 아래와 같이 동작한다.  
![KakaoTalk_20220504_015536921](https://user-images.githubusercontent.com/57346428/166502496-833345cc-cdfc-4074-8f3e-d36ff3eab3b0.jpg)


# 2. 새로 배운 내용(코드 위주)