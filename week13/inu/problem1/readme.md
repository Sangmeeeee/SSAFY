# Info

  

문제 : [거짓말](https://www.acmicpc.net/problem/1043)

알고리즘 종류 : 분리집합

참조 url : 

  

# 알고리즘 설명
1. 진실을 알고 있는 사람들의 분리집합을 만든다.
- 가장 먼저 입력 받은 사람을 루트로 설정한다. (=tRoot)
- 진실을 아는 사람이 0명이 아닐 때만 분리집합을 만든다.
- 진실을 아는 사람이 2명 이상이면 height[tRoot] = 2로 해준다.  

2. 각 파티에 대해 union-find
- 가장 먼저 입력받은 사람과 그 뒤의 사람들을 각각 union-find를 한다.
- 두 사람의 root parent가 다를 때만 union을 하면 된다.
- tRoot, height를 기준으로 union을 한다.

3. 각 파티 구성원 확인
- 각 파티 구성원의 root parent가 tRoot가 아니면 과장된 이야기가 가능하다.

# 새로 배운 내용
