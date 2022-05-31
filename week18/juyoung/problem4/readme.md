# Info

문제 : [주차 요금 계산](https://programmers.co.kr/learn/courses/30/lessons/92341)

알고리즘 종류 : 

참조 url : 


# 1. 알고리즘 설명

입차 시간을 저장하는 map `inoutInfo`와 총 주차 시간을 저장하는 map `parkingTime`을 선언한다.  

1. 전체 레코드에 대해 `parkingTime`에 [key: 차량 번호, value: 총 주차 시간] 형태로 저장한다.
	1. 입차한 기록이라면 `inoutInfo`에서 차량 번호를 key로 하는 원소에 입차 시간을 삽입한다.
	2. 출차한 기록이라면 `inoutInfo`에서 차량 번호를 찾아 주차 시간을 계산한다.
		- 이미 주차된 적 있다면 `parkingTime`에서 차량 번호를 key로 하는 원소에 주차 시간을 더한다.
		- 처음 주차한 거라면 `parkingTime`에서 차량 번호를 key로 하는 원소에 주차 시간을 삽입한다.
		- `inoutInfo`에서 해당 차량의 입차 시간을 `""`로 초기화한다.
2. 만약 `inoutInfo`에 아직 입차 시간이 남아있다면, 23:59에 출차한 것으로 간주한다.
	- 입차 시간 ~ 23:59 사이의 주차 시간을 구해서 `parkingTime`을 업데이트 한다.
3. `parkingTime`에 저장된 정보를 바탕으로 주차 요금을 계산하고, `answer`에 삽입한다.


# 2. 새로 배운 내용(코드 위주)
