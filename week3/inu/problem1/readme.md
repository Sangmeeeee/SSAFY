# Info

  

문제 : [카드 정렬하기](https://www.acmicpc.net/problem/2866)

알고리즘 종류 : 우선순위 큐

참조 url : 

  

# 알고리즘 설명
우선순위 큐를 이용하면 매우 쉽게 해결할 수 있다.
카드 묶음의 수가 1개일 때와 2개 이상일 때를 나눠서 생각해야한다.
- N == 1
1. 비교할 일이 없기 때문에 답은 0이다.  

- N >= 2
1. 모든 카드 묶음을 우선순위 큐에 넣는다.
2. 2개씩 꺼내서 더한 것을 sum에 더하고 다시 우선순위 큐에 넣는다.
3. 이 과정을 N-1번 반복한다.

# 새로 배운 내용
우선순위 큐의 정렬을 오름차순으로 할 지 내림차순으로 할 지 정할 수 있다. 
default는 내림차순이다.
```c++
//1
priority_queue<int> pq;
//2
priority_queue<int, vector<int>, less<int>> pq;
//3
priority_queue<int, vector<int>, greater<int>> pq;
```
1, 2는 동일한 내림차순의 우선순위 큐이고 3은 오름차순의 우선순위 큐다.
