문제 : [[탈출]](https://www.acmicpc.net/problem/3055)

알고리즘 종류 : BFS

참조 url :

# 1. 알고리즘 설명(로직위주)

## 문제 이해

한방에 맞아버리니 아주 기분이 좋았다. 문제는 수업 시간에 했던 아기상어 문제와 비슷했다. time 에 따라서 map 이 바뀌거나 상태가 바뀌는 문제일때 이와 같은 로직을 따라가면 좋을것 같다.

처음에는 map을 3차원 배열로 해서 모두 time 마다 모든 맵을 만들어 주려다가 이는 비효율 적임을 깨닫고 두개의 queue를 쓰는 방법을 생각해냈다.

## 로직

queue 가 두개가 있다 queue 를 while문을 돌면서 사방 탐색을 하며 지나 갈 수 있는 곳을 체크 해주며 nextQueue라는 새로운 queue 에 모두 offer를 해준다. 이후 while문을 빠져나왔을때 queue 를 nextQueue 로 바꿔주면서 다시 while문으로 들어가서queue를 비워주는 작업을 반복했다. queue와 nextQueue가 모두 비었을때 최종 while문을 빠져나오며 answer를 출력했다.

# 2. 새로 배운 내용(코드위주)

inbound 라는 함수를 만들어줬는데 이렇게 만들어 두는게 로직 짤때 훨씬 머리에 잘들어옴을 느꼈다. 머리에 박아두면 좋겠다.

```java
static boolean inbound(int y, int x){
        if(x<0 || C<=x||y<0 || R<=y)return false;
        return true;
    }
```