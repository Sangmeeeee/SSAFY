문제 : [[토마토]](https://www.acmicpc.net/problem/7576)

알고리즘 종류 : BFS

참조 url :

# 1. 알고리즘 설명(로직위주)

## 문제 이해

두개의 queue를 쓰는 방법을 생각했다 문제가 모두 비슷했다.

## 로직

queue 가 두개가 있다 queue 를 while문을 돌면서 사방 탐색을 하며 지나 갈 수 있는 곳을 체크 해주며 nextQueue라는 새로운 queue 에 모두 offer를 해준다. 이후 while문을 빠져나왔을때 queue 를 nextQueue 로 바꿔주면서 다시 while문으로 들어가서queue를 비워주는 작업을 반복했다. queue와 nextQueue가 모두 비었을때 최종 while문을 빠져나오며 answer를 출력했다.

# 2. 새로 배운 내용(코드위주)