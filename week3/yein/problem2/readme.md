# Info

문제 : [파일 합치기 3](https://www.acmicpc.net/problem/13975)

알고리즘 종류 : 우선순위 큐

참조 url : 없음

# 알고리즘 설명

1. 그리디 알고리즘을 적용해야하는 문제로 작은 값을 먼저 꺼내서 더해줘야지 항상 최솟값을 구할 수 있다.
2. 작은 값을 꺼내기 위해서 우선순위 큐를 활용했고 숫자 두개를 꺼내주고 난 후 더해준다.
3. 더해준 값을 답을 저장하는 변수 ans에 계속해서 플러스 해준다.
4. 그리고 더한 값을 다시 큐에 넣어준다. 
5. 큐의 길이가 1보다 작아지기 전 까지 계속해서 반복해준다.

# 새로 배운 내용
