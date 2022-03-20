# Info

  

문제 : [선수 과목](https://www.acmicpc.net/problem/14567)

알고리즘 종류 : 위상정렬

참조 url : 

  

# 알고리즘 설명
맨 처음에 진입 차수가 0인 노드를 찾아야 하기 때문에 inEdge배열을 둬서 선수과목 조건 A, B가 주어질 때마다 inEdge[B]++을 한다.  
그리고 inEdge[i] == 0인 i만 큐에 넣고 위상정렬을 한다.  

```c++
	int semester = 1;

	while (!q.empty()) {
		int qsize = q.size();
		
		for (int i = 0; i < qsize; i++) {
			int u = q.front(); q.pop();
			ans[u] = semester;

			for (int j = 0; j < (int)subject[u].size(); j++) {
				if (--inEdge[subject[u][j]] == 0)
					q.push(subject[u][j]);
			}
		}
		
		semester++;
	}
```
- 현재 큐에 들어있는 모든 과목은 같은 학기에 이수하는 과목이므로 첫번째 for문에서 각 과목마다 ans[u] = semester를 해주고 해당 for문이 끝나면 semester++를 한다.
- 큐에서 pop한 과목은 현재 그래프에서 없애야 하기 때문에 해당 과목과 연결된 과목들의 진입 차수를 하나 줄여준다.
	- 이 때 줄인 진입 차수가 0이면 다음 학기에 이수할 수 있는 과목이므로 큐에 넣어준다.
- 큐가 빌 때까지 위 과정을 반복하면 된다.

# 새로 배운 내용

