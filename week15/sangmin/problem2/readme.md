문제 : [오픈채팅방](https://programmers.co.kr/learn/courses/30/lessons/42888)

알고리즘 종류 : Map, Queue

참조 url :

# 1. 알고리즘 설명

큐에 저장된 명령어에 따라 알맞은 형식으로 출력해주면 되는 문제이다.

대신 큐에는 사람의 이름이 아닌 고유한 아이디인 uid를 저장해서 메시지를 출력할때마다 uid와 mapping되어있는 name을 출력해준다.

Map에는 uid가 key, userName이 value로 저장되어있고

Queue에는 command와 uid를 클래스 멤버로 가지는 Node 클래스를 담아준다.

# 2. 새로 배운 내용
