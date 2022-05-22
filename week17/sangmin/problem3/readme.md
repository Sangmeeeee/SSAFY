문제 : [[1차] 캐시](https://programmers.co.kr/learn/courses/30/lessons/17680)

알고리즘 종류 : 구현

참조 url : 

# 1. 알고리즘 설명

cacheSize가 0이라면 cities 길이 * 5를 return 해준다.

만약 cacheSize가 0보다 크다면 cache를 채워준다.

LRU이기 때문에 가장 최근에 사용한 city를 cache에 넣어줘야한다.

중간에 있는 엘리먼트를 빼야하는 경우가 많을 수 있기 때문에 ArrayList보다 LinkedList를 사용한다.

LinkedList의 contains 메소드를 이용해서 넣으려는 city가 포함되어있다면 hit이기 때문에

city를 제거해주고 다시 list에 넣어준다. (LRU 이기 때문에)

만약 miss라면 두가지로 나뉜다.

1. list의 크기가 cacheSize보다 작을경우
2. list의 크기가 cacheSize일 경우

1번 경우는 단순히 list에 넣어주고 time을 5 증가해준다.

2번 경우는 list의 0번째 원소를 제거하고 list에 현재 city를 넣어준 후 time을 5 증가해준다.

# 2. 새로 배운 내용
