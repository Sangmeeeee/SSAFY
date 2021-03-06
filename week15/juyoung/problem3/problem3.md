# Info

문제 : [카카오 프렌즈 컬러링북](https://programmers.co.kr/learn/courses/30/lessons/1829)

알고리즘 종류 : BFS

참조 url :


# 1. 알고리즘 설명

BFS로 간단하게 풀 수 있는 문제였다.  
그림의 첫번째 원소부터 마지막 원소까지 탐색하는데, 0이 아니면서 방문하지 않은 원소에 대해서만 BFS를 수행했다.  

BFS를 수행할 땐 시작 원소의 값(색깔)과 똑같은 값을 가진 원소만 queue에 삽입한다.  
그리고 queue에 삽입할 때마다 영역의 넓이를 저장하는 `cnt` 변수를 증가시키고,  
queue가 비었을 때 `max_size_of_one_area`와 `cnt`를 비교하여 더 큰 값으로 갱신한다.

bfs 수행이 끝난 후에는 한 영역의 넓이 계산이 끝난 것이므로 `number_of_area`를 1만큼 증가시킨다.

이 문제에서 가장 유의해야 할 부분은 초기화였던 것 같다.


# 2. 새로 배운 내용(코드 위주)