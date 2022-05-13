문제:  [여행가자](https://www.acmicpc.net/problem/1976)

알고리즘 종류 : union-find

참조 url : [[union-find 알고리즘 설명]](https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html)

# 1. 알고리즘 설명(로직위주)

## 문제 이해

### Union-Find

참 쉬운데 항상 틀리곤 해서 자신이 없었던 문제 유형.

이번에 쭉 정리를 한 문제를 통해서 해 보았다. 

1. make-set(x) : 집합을 초기화(보통 하나하나 다른 집합으로 초기화.)
2. union(x,y) : x가 속한 집합과 y가 속한 집합을 합치는 연산
3. find(x) : x가 속한 집합의 대표값(루트 노드값) 을 반환하는 연산. 어떤 집합에 속해있는지 찾는 연산.

### Union-Find 에서 구현 해야하는 기능

### 배열 방법과 트리 방법

배열 방법과 트리 방법이 있다는 것은 알았지만, 배열을 쓰면 트리가 아니다? 라는 무식한 생각을 했다. 

### 배열 (트리 자료구조와 차이를 느껴라)

자료구조에 생긴 형태를 생각 해보면 각각의 원소의 내용물은 집합의 root노드값을 가지고 있다.

find(x) :  x가 속한 집합 번호를 찾는다. O(1)

union(x,y) : 배열의 모든 원소를 순회 하면서 y의 집합 번호를 가진 원소를 x의 집합번호로 변경한다. 따라서 시간 복잡도 O(N)

union 을 무조건 조상부터 끝까지 돌아야 하기에 N 이 커지면 트리의 재귀로 인한 overhead 보다 더 안 좋아 질 수 있겠다.

### 트리 (배열 자료구조와 차이를 느껴라)

자료구조에 생긴 형태를 생각 해보면 각각의 원소의 내용물은 해당 원소의 부모 노드 값을 가지고 있다. 루트노드값이 아니라서 여러번 타고 올라가야 하기에 find가 재귀적으로 만들어 지게 되어있다.

find : 노드의 원소는 부모의 노드 번호를 담고 있고, 자기 자신을 가리킬 때 루트 노드이므로 재귀적으로 올라가며 루트노드를 확인한다.

union : x,y의 루트노드를 find 를 통해 찾고 이를 한쪽으로 합한다.