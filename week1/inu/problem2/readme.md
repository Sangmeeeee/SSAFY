
# Info

  

  

문제 : [이차원 배열과 연산](https://www.acmicpc.net/problem/17140)

  

  

알고리즘 종류 : 정렬, 구현

  

  

참조 url : https://www.acmicpc.net/board/view/67506

  

  

# 알고리즘 설명

- R >= C인 경우 (R < C는 아래 과정을 열에 대해 반복)

1. 현재 행에 있는 수들의 등장 횟수를 세서 배열(cnt)에 저장한다.

2. cnt 배열에 저장된 등장 횟수와 인덱스를 pair로 벡터에 넣고 정렬한다.

3. 벡터에서 차례대로 pair 꺼내서 배열에 넣는다.

각 pair는 2개의 숫자를 가지므로 해당 행에 들어갈 숫자들은 벡터 크기 * 2(q_size)개 만큼 들어간다.

이 때, q_size를 넘어가는 부분은 0으로 바꿔준다.

4. 모든 행에 대해 반복하면서 가장 큰 q_size를 찾는다. 이 q_size는 전체 배열의 열 크기가 된다.

- 최대 100번 동안 R과 C를 비교해서 위 과정을 수행한다.

- R과 C를 비교하기 전에 A[r][c] == k 인지 확인한다.

  

# 새로 배운 내용

c++에서는 algorithm 헤더파일에 sort()라는 정렬 함수가 구현되어 있다.

퀵소트 기반이기 때문에 O(nlogn)의 시간복잡도를 가진다.

```c++

sort(start, end); // [start, end)를 오름차순으로 정렬

sort(start, end,  grearter<자료형>()); // [star, end)를 내림차순으로 정렬

sort(start, end, compare); // [star, end)를 사용자 기준으로 정렬

```

  

~~이 때, pair가 들어간 벡터는 sort()를 바로 사용할 수 없기 때문에 비교함수를 따로 설정해야 한다.~~  
다시 확인하니까 사용자 정의 비교함수 없어도 잘 된다.
first, second 모두 오름차순이기 때문에 문제가 없는데 하나는 오름차순, 하나는 내림차순으로 하고 싶으면 비교함수를 설정하면 된다.

```c++

bool  compare(pair<int,  int> p1,  pair<int,  int> p2)  {

if  (p1.first == p2.first)

return p1.second < p2.second;

return p1.first < p2.first;

}

```

- 각 pair의 first를 우선으로 오름차순으로 정렬하는데, first가 서로 같으면 second를 오름차순으로 정렬한다.

- 헷갈리면 비교연산자의 방향을 보면 된다.

a < b는 배열의 왼쪽 요소가 오른쪽 요소보다 작게 정렬하겠다는 뜻이다. 즉, 오름차순이다.

반대로 a > b로 하면 왼쪽 요소가 오른쪽 요소보다 크게 정렬하겠다는 뜻이므로 내림차순이 된다.
