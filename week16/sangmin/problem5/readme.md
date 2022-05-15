문제 : [순위 검색](https://programmers.co.kr/learn/courses/30/lessons/72412)

알고리즘 종류 : map, 이분탐색

참조 url : https://jisunshine.tistory.com/153

# 1. 알고리즘 설명

만약 info의 문자열이 python backend junior pizza 150이라면

포함되는 문자열은

1. \- backend junior pizza
2. python - junior pizza
3. python backend - pizza
4. python backend junior -
5. \- - junior pizza
6. \- backend - pizza
7. \- backend junior -
8. python - - pizza
9. python - junior -
10. python backend - -
11. \- - - pizza
12. \- - junior -
13. \- backend - -
14. python - - -
15. \- - - -
16. python backend junior pizza

이렇게 16가지가 나온다.

한번 넣을때 for문을 이용해서 모든 경우에 대해 map에 넣어주고 다 넣었다면 map에 넣어둔 list들을 전부 정렬해준다.

정렬해준 list를 이분탐색을 통해 lower bound로 idx를 검색해주고 size - idx를 정답으로 해준다.

# 2. 새로 배운 내용
