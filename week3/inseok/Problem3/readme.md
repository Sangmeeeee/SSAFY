문제 : [[메뉴 리뉴얼]](https://programmers.co.kr/learn/courses/30/lessons/72411)

알고리즘 종류 : 맵

참조 url : 없음

# 1. 알고리즘 설명(로직위주)

## 문제 이해

문제 자체가 이해가 너무 어려웠다.. 상민이 한테 물어본 후에야 CF 와 같은 예시가 안되는지 알게 되었다. String 자체가 sorted 가 안되어있어서 그걸 char[] 로 바꾼 후에 Arrays.sort 를 해서 다시 string 을 만들어 주었다.

## 로직

소팅을 해준 후 

문자열마다 combination 을 해주었다. 그것을 Map에 저장 해주엇고, maxValue 를 계속 바꾸어 주면서 PriorityQueue 에다가 가장 큰 녀석 들만 저장해주었다.

이후 Queue를 poll 해주면서 answer를 만들어 주었다.

# 2. 새로 배운 내용(코드위주)