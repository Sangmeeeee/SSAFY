문제 : [주차 요금 계산](https://programmers.co.kr/learn/courses/30/lessons/92341)

알고리즘 종류 : 

참조 url : 

# 1. 알고리즘 설명

Map을 2개 둬서 하나는 차고, 하나는 이미 나온 상태를 저장해준다.

차고 Map에는 차 번호와 출입 시간, 나온 상태를 저장하는 Map에는 차 번호와 총 시간을 입력해준다.

그 후 records 문자열 배열을 돌며 IN일 경우 차고에 넣어주고 OUT일경우 나온 상태에 시간과 계산한 시간을 더해 다시 넣어주고

out의 keySet을 리스트로 만든 후, 정렬해주고 나온 상태에 key를 받아 요금을 계산해준다.

# 2. 새로 배운 내용
