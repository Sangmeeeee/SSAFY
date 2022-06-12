문제 : [불량 사용자](https://programmers.co.kr/learn/courses/30/lessons/64064)

알고리즘 종류 : 

참조 url : 

# 1. 알고리즘 설명

처음에는 트라이 자료구조를 사용하는 방식인가 싶었지만 user_id 배열의 크기가 8이하이고, 아이디도 전부 길이가 8이하이기 때문에 하나하나 대조할 수 있겠다 생각했다.

userId와 bannedId를 비교해서 만약 bannedId와 userId가 맞다면 match시켜주고 dfs를 통해 match된 userId의 개수가 banned_id 배열의 크기와 같다면

set을 이용하여 match된 user_id의 문자열들을 중복없이 set에 넣어준다.

결과적으로 set의 크기가 나올 수 있는 모든 경우의 수를 나타낸다.

# 2. 새로 배운 내용
