문제 : [오민식의 고민](https://www.acmicpc.net/problem/1219)

알고리즘 종류 : 벨만포드

참조 url :

# 1. 알고리즘 설명

[골목길](https://www.acmicpc.net/problem/1738) 문제와 똑같다.

다만 골목길 문제는 parent 배열을 두어 경로를 출력해주고 만약 경로상에 싸이클이 존재하거나 마지막 노드에 도착할 수 없을 경우 -1을 출력해주고

이 문제는 parent배열을 둘 필요없이 경로상에 싸이클이 존재하면 Gee, 마지막 노드에 도착할 수 없을 경우 gg를, 도착가능하다면 이익을 출력해준다.

조금 더 추가 되었다면 벨만포드는 최단경로를 구하는것이기 때문에 각 노드에 방문하면 수익을 + 해주는게 아닌 - 해줘야한다.

# 2. 새로 배운 내용

<img width="578" alt="스크린샷 2022-04-17 오후 6 01 25" src="https://user-images.githubusercontent.com/24482602/163707846-b19e6a31-42e5-43f8-83fe-66ade112ad3a.png">

![Unknown](https://user-images.githubusercontent.com/24482602/163707858-0026fb40-5ed7-46f7-93b9-d7aad64a4322.jpeg)
