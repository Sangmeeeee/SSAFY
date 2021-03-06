# Info

  

문제 : [한 번 남았다](https://www.acmicpc.net/problem/13317)

알고리즘 종류 : 벨만포드

참조 url : 

  

# 알고리즘 설명
이 문제는 입력값을 받아서 답을 내는 것이 아니라 주어진 코드가 잘못되었음을 증명할 수 있는 반례를 만드는 새로운 유형의 문제이다.  
이때까지 내가 구현했던 벨만포드와 조금 다른 점이 있다.  
- 최단 경로 길이를 저장하는 배열 dist를 0으로 초기화한다.
- 그래프를 인접 리스트나 인접 행렬로 저장하지 않고 (시작점, 끝점, 가중치) 형태로 저장한다.
- 간선의 가중치가 1 또는 -1이다.

위의 조건과 주어진 코드를 통해 다음과 같이 유추할 수 있다.
- 정점 u, v가 있고 u에서 v로 가는 간선을 w(u, v)라 할 때, d[v]는 d[v] > d[u] + w(u, v)일 때 갱신된다. 여기서 첫 번째 조건을 고려하면 d[v]는 음수로만 갱신될 수 있다.  
- 정점의 개수를 V라고 하면 벨만포드는 완화 작업을 (V - 1)번 반복한다. 지구이는 완화 작업을 (V - 2)번만 하고 음수 사이클이 없음에도 (V - 1)번째 완화 작업이 성공해서 음수 사이클이 있다고 판단하기 때문에 (V - 1)번 모두 d배열의 갱신이 이루어져야 한다.
- 정상적인 벨만포드 알고리즘으로는 정답이 나와야하기 때문에 음수사이클이 있으면 안된다.

종합하면 (V - 1)번에 거쳐서 d배열의 갱신이 이루어지고 이 때 음수가 커지도록 갱신이 되어야 한다.  
이를 만족하는 입력은 정점이 V개, 간선이 V - 1개이며 각 간선은 가중치가 -1인 w(i + 1, i) (1 <= i < V)이다. 그리고 입력이 다음과 같은 순서로 되어야 (V - 1)번 갱신이 될 수 있다.
``` c++
// 50 <= V <= 100
50 49
2 1 -1
3 2 -1
.
.
.
49 48 -1
50 49 -1
```


# 새로 배운 내용
