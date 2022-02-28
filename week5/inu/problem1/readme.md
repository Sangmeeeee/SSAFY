# Info

  

문제 : [감소하는 수](https://www.acmicpc.net/problem/1038)

알고리즘 종류 : 백트래킹

참조 url :

  

# 알고리즘 설명
문제에서 만족하는 감소하는 수 중에서 가장 큰 수는 9876543210이다.  
따라서 길이가 1인 것부터 10인 것까지 각 길이별로 0으로 시작하는 정수부터 9로 시작하는 정수 중 감소하는 수를 백트래킹으로 찾는다.
1. 0부터 (마지막으로 넣은 정수 - 1)까지 문자열에 추가한다.
2. 문자열의 길이가 일정 길이와 같아지면 카운트를 증가시킨다.
3. 카운트가 입력받은 N과 같으면 현재 문자열을 출력하고 종료한다.

N이 0부터 시작하기 때문에 cnt 변수를 -1부터 시작했다.

# 새로 배운 내용