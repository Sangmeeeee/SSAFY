# Info

  

문제 : [두 용액](https://www.acmicpc.net/problem/2470)

알고리즘 종류 : 투 포인터

참조 url : 

  

# 알고리즘 설명
두 용액 특성값 합이 가장 0에 가까워야 하기 때문에 음수와 양수를 더하는 것이 가장 정답에 가까울 가능성이 크다.  
따라서 특성값을 담은 배열을 오름차순으로 정렬해서 맨 처음와 맨 뒤를 가리키는 변수를 두고 두 값을 비교해서 인덱스를 조절한다.
- solution: 특성값 배열, i: 맨 앞 인덱스, j: 맨 뒤 인덱스
- |solution[i] + solution[j]|가 현재 최소값보다 작다면 답을 바꿔준다.
	- 만약 이 값이 0이면 반복문을 종료하고 바로 정답을 출력하면 된다.
- |solution[i]| > |solution[j]|이면 i를 1만큼 늘리고 아니면 j를 1만큼 감소한다.


# 새로 배운 내용

