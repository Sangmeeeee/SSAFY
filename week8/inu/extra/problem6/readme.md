# Info

  

문제 : [ACM Craft](https://www.acmicpc.net/problem/1005)

알고리즘 종류 : 위상정렬

참조 url : 

  

# 알고리즘 설명
이전에 풀었던 위상정렬 문제인 [작업](https://www.acmicpc.net/problem/2056)과 [줄 세우기](https://www.acmicpc.net/problem/2252)를 합친 문제이다.  
- 현재 건물을 짓기 전에 지어야 하는 건물들 중 가장 늦게 끝나는 건물의 종료 시간에 현재 건물의 건설 시간을 더해야 한다.
- 건물들 간의 관계를 그래프로 표현했을 때 여러 개의 그래프로 나타날 수 있기 때문에 W를 찾을 때까지 각 그래프에 대해서 위상정렬을 해야한다.  

```c++
	// 진입 차수가 0인 노드 찾기
	vector<int> start;
	for (int i = 1; i <= N; i++)
		if (indegree[i] == 0)
			start.push_back(i);

	// W 찾을 때까지 위상정렬
	for (int s : start) {
		int ans = topological_sort(W, s);
		if (ans != -1) {
			cout << ans << '\n';
			break;
		}
	}
```
- 어떤 그래프에 대한 topological_sort() 함수를 실행했을 때 함수 내에서 W를 찾았으면 그 건물의 건설 종료 시간을 반환하고 아니면 -1을 반환하도록 했다.
# 새로 배운 내용

