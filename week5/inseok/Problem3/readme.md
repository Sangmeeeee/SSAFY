문제 : [[캠프준비]](https://www.acmicpc.net/problem/16938)

알고리즘 종류 : backTracking

참조 url :

# 1. 알고리즘 설명(로직위주)

## 문제 이해

backTracking을 더 심하게 하려다가 내 머리속에서 로직이 꼬여서 거기서 고생했다. subSet 구하는 방식, 재귀로문제를 접근했다. 

## 로직

combination이라고 함수이름을 썼지만 사실 subSet이 더욱 맞다.

idx가  모두 찼을때 sum 이 L,R사이에 해당하고 X보다 내가 고른 수들의 차이가 클때 answer++ 를 해주고, sum 이 R보다 크면 return 을 해주며 재귀를 통해 해결하였다.

# 2. 새로 배운 내용(코드위주)