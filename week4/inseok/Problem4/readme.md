문제 : [[ABCDE]](https://www.acmicpc.net/problem/13023)

알고리즘 종류 : 그래프, DFS

참조 url :

# 1. 알고리즘 설명(로직위주)

## 문제 이해

정점 N과 간선 M 이 첫번째 줄 input 으로 주어지고, 두번째 줄부터 정점간의 연결을 input으로 준다. 이를 다섯번 타고 들어가는 관계가 있는지를 찾아야하는것이 이문제의 목표다.

인접리스트 오늘 수업에서 배웠는데 오랜만에 연습하는 계기가 되어서 좋았다. 일단 다섯번을 들어가야하니 DFS 를 쓰는게 좋겠다는생각을했고 배열, 인접리스트 , 간선리스트 중에 아무래도 인접 리스트가 좋겠다는 생각을 했다.(다른 방법도 하려면 할수 있을듯?)

리스트로 만들어진 배열을 만드는거 저번에 해본적 있었는데 그게 도움이 되었다.(생성자 여러번 만들어줘야하는거)

## 로직

### main함수

먼저 List<Integer> adjList 라는 인접리스트를 나타내는 리스트 배열을 만들어 주고 이를 간선을 받아와 초기화 해준다.

이후 boolean[] visited을 바꿔주면서 idx 마다 dfs 를 타고 들어가는 로직을 썼다. 

### dfs 함수

basis part(기저조건) : depthFlag 가 켜져있다면 return 하고, depth 가 5이면 depthFlag를 켜주면서 return 한다.

inductive part(유도 조건) : idx 가 현재 정점 위치이고 adjList[idx] 에 붙어있는 integer들이 나와 연결된 정점들의 idx 이다. visited[]에 친구들이 아직 들린적이 없는지를 보면서 들리지 않았다면 visited를 수정해주면서 dfs를 한번더 타고 들어가도록 했다.

# 2. 새로 배운 내용(코드위주)

## 저번에 했던 List 배열 초기화 방법

```java
static List<Integer>[] adjList;
public static void main(String[] args) throws IOException {

	adjList = new ArrayList[N];
	
	for(int i=0;i<N;i++){
	adjList[i] = new ArrayList<>();
	}
}
```

까먹을까봐 한번 더 적어 보았다.