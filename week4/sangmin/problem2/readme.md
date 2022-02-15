문제 : [트리](https://www.acmicpc.net/problem/4803)

알고리즘 종류 : DFS, UnionFind

참조 url : https://loosie.tistory.com/460

# 1. 알고리즘 설명

## 1.1 UnionFind

DFS문제였지만 처음 접근은 UnionFind로 접근했다.

![image](https://user-images.githubusercontent.com/24482602/154118663-0fe1ad4a-1d2d-4ff1-8165-b04b507d6b0c.png)

int[] parent 배열에는 각 노드들의 부모 노드 정보가 담겨있다. 맨 처음은 각각 자신이 자신의 부모이기 때문에 각각의 노드 번호가 담겨있다.

먼저 간선을 하나 입력 받으면 각 간선의 끝에있는 노드의 부모를 찾는다.

두 노드의 부모가 다르다면 한 노드의 부모를 다른 노드의 부모로 설정해준다. 이 때 노드의 부모가 더 작은쪽을 다른 한쪽 노드의 부모의 부모로 삼는다.

```java
    if(num1Parent < num2Parent) {
        parent[num2Parent] = num1Parent;
    }else if(num1Parent > num2Parent){
        parent[num1Parent] = num2Parent;
    }
```

원래대로라면 둘중 어느 노드에 합쳐도 상관이 없지만 작은 쪽을 부모로 설정한 이유는 cycle의 판단 때문이다.

cycle이 만들어지는 조건은 입력받은 노드의 부모가 같을때 일어난다. 간선을 잇는다는 소리는

노드1의 시작(노드 1의 부모)과 노드2의 끝(노드 2의 부모)을 같은 줄에 놓는다는것과 같은데 만약 노드1의 시작과 노드2이 같다면 시작과 끝이 같다는 소리이기 때문에

cycle이 만들어진다. 여기서 두 노드가 부모가 같다면 cycle이라는 뜻으로 한쪽 노드의 부모를 다른 쪽 노드의 부모로 설정하고 0으로 바꿔준다.

```java
    if(node1Parent == node2Parent){
        parent[node2Parent]=node1Parent;
        parent[node1Parent]=0;
    }
```

그렇다면 만약 어느 한 cycle에 속한 노드와 다른 트리의 노드가 연결되어있는 상황을 가정했을때 각 노드의 부모를 찾는다면

````java
    node1Parent = 0; // cycle
    node2Parent = n; // tree
````

이 될것이고 무분별하게 노드의 부모를 합쳐버리면 아래의 상황처럼 cycle로 판단됬던 트리가 cycle이 아니게 될 수 있다.

````java
    parent[node1Parent] = node2Parent;
    parent[0] = n;
````

이 때문에 작은쪽으로 합쳐야한다.

이를 모든 간선에 대해 UnionFind를 진행하고 나면 parent 배열이 tree의 root를 가르키고 있거나 cycle이라고 판단(0)되어있기 때문에 count 해준다.

## 1.2 DFS

DFS는 일단 모든 간선의 정보를 입력 받고 DFS해주면서 판단하는 과정을 가진다.

일단 간선을 입력받으면 양방향으로 만들어 준다.

![image](https://user-images.githubusercontent.com/24482602/154118663-0fe1ad4a-1d2d-4ff1-8165-b04b507d6b0c.png)

먼저 1번 노드에서 시작한다. 이때 1번 노드를 방문했다는 표시를 해준다(boolean[] isVisit)

그 후, 1번 노드에 연결되어있는 모든 노드를 탐색한다. 위 그림에서는 2번 노드밖에 존재하지 않는다.

2번 노드를 방문하면서 2번 노드를 방문했다는 표시를 해주고

2번 노드에 연결되어있는 노드는 1번과 3번 노드이다. dfs를 재귀적으로 할때 before 정보를 줘서 이 전으로는 다시 돌아가지 않는다.

즉 2번 노드에서는 1번으로 다시 돌아가지 않는다. 남는 노드는 3번이기 때문에 3번으로 가주고 결국 4번까지 도달하면 dfs가 종료된다.

dfs 종료시 트리의 개수를 하나 증가해준다.

위와같은 탐색을 끝내고 나면 isVisit 배열은

    true true true true false false

이와 같이 된다.

1번 노드의 탐색이 끝나면 2번 노드로 가야하는데 2번 노드는 이미 방문했으니까 5번 노드로 간다.

5번 노드는 5번 노드밖에 없기 때문에

    true true true true true false

와 같이 되고 트리의 개수는 2개가 된다.

마지막 6번까지 탐색하면 3개의 트리가 나오게 된다.

cycle의 판단은 dfs를 재귀로 탐색하는 중에 일어난다.

만약 노드와 연결되있는 다른 노드들 중 before 노드가 아니지만 이미 방문한 노드가 하나라도 존재한다면 이 트리는 cycle이 된다.

만약 cycle로 판단되었다면 count를 해주지 않는다.

# 2. 새로 배운 내용

