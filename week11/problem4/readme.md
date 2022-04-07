# Info

  

문제 : [호석이 두 마리 치킨](https://www.acmicpc.net/problem/21278)

알고리즘 종류 : 플로이드-와샬

참조 url : 

  

# 알고리즘 설명
일단 플로이드로 모든 두 빌딩 간의 최단 경로 길이를 구한다.  
그 후에 빌딩 2개를 치킨집으로 했을 때 나머지 빌딩과 가장 가까운 치킨집 사이의 거리합을 찾아서 현재값과 비교하여 갱신하면서 최솟값을 찾는다.
```c++
// c1, c2는 치킨집을 연 빌딩
int chicken(int c1, int c2) {
	int sum = 0;
	// i번째 건물과 가장 가까운 치킨집 사이의 거리를 더한다
	for (int i = 1; i <= N; i++)
		sum += min(graph[i][c1], graph[i][c2]);
	// 왕복 거리이므로 2를 곱해준다
	return sum * 2;
}
```
```c++
int time = chicken(i, j);
if (time < minTime) {
	minTime = time;
	building = { i, j };
}
// 왕복 거리가 같으면 건물 번호를 비교한다.
else if (time == minTime) {
	// 작은 번호의 건물이 더 작아야 함
	if (i < building.first)
		building = { i, j };
	else if (i == building.first) {
		// 큰 번호의 건물이 더 작아야 함
		if (j < building.second)
			building = { i, j };
	}
}
```



# 새로 배운 내용
