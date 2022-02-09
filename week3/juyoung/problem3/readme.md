# Info

문제 : [메뉴 리뉴얼](https://programmers.co.kr/learn/courses/30/lessons/72411)

알고리즘 종류 : map

참조 url :


# 1. 알고리즘 설명

1. 코스 메뉴 개수에 따라 **각각의 주문한 단품 메뉴에 대한 가능한 모든 조합을 map에 저장**함과 동시에 해당 조합의 개수를 카운트한다.
	- $_nC_r = _{order.length}C_{course}$
	- 이때, 주문한 단품 메뉴를 정렬한 후 조합을 구해야 제대로 카운트된다.
   
2. map의 값을 vector에 복사하여 value를 기준으로 내림차순 정렬하고, 가장 많이 주문된 조합을 `answer` vector에 저장한다.


# 2. 새로 배운 내용(코드 위주)
