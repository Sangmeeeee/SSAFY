문제 : [[톱니바퀴]](https://www.acmicpc.net/problem/14891)

알고리즘 종류 : 시뮬레이션&구현

참조 url :

# 1. 알고리즘 설명(로직위주)

## 문제 이해

구현 문제였다. 처음에 비트를 이용해서 shift 연산과 xor을 통해서 회전을 해보려다가, 쉬운 방식으로 접근 하고 싶어서 boolean 2차원 배열로 톱니바퀴를 구현했다.(xor은 이용하려고)

### 구현 문제 접근은 이렇게 해보자.

처음에 움직일 때 마다 점수를 더해주는 방식으로 생각해서 문제 디버깅 하다가 문제를 잘못 이해했다는 것을 이해했다. 입력을 보면서 내가 생각한 방식과 맞는지 돌려 보는게 구현문제에선 좋을 것같다. 

## 로직

### main

boolean [4][8] wheel 에 톱니바퀴 내용을 저장한다. K회 회전 정보를 입력 받는데 물려있는 톱니에 의해 다른 톱니바퀴들이 같이 돌 수도 있기에, int[4] linkMove 를 이용해서 돌지 안 돌지를 체크한다(xor이용).  수정해준 linkMove 정보에 따라 wheel 들을 모두 shift함수를 통해 회전시켜준다. 

모두 회전시킨 이후에 wheel[i][0] 들을 모두 더해주었다.

### shift(int num, int dir)

num : 회전시킬 톱니바퀴, dir : 는 회전 시키는 방향이다. 배열을 dir 에 따라 수정해주었다.

# 2. 새로 배운 내용(코드위주)