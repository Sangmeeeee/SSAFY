# Info

문제 : [서강그라운드](https://www.acmicpc.net/problem/14938)

알고리즘 종류 : 플로이드 와샬

참조 url : 


# 1. 알고리즘 설명

플로이드 와샬 알고리즘을 이용해서 풀었다.

입력을 통해 인접 행렬을 만들 때, 그래프가 양방향이므로 하나의 입력에 대해 2개의 원소를 채워줘야 한다.  
또한 인접 행렬을 생성한 후에 자기자신이 아니면서 연결되지 않은 곳은  
플로이드 와샬 알고리즘 적용을 위해 충분히 큰 수로 초기화해야 한다.

이후 플로이드 와샬 알고리즘을 통해 인접 행렬의 원소들을 업데이트한다.

마지막으로 인접 행렬을 행 단위로 탐색하며  
해당 지역(=행)에 떨어졌을 때 수색 범위 내 지역의 아이템 개수를 누적하며 더해준다.  
즉, 인접 행렬에 저장된 값이 최단 거리이므로 각 원소가 수색 범위(`r`)보다 작은 것을 더한다.  
더한 값과 현재 얻을 수 있는 아이템의 최대 개수를 비교하여 더 큰 수로 정답을 갱신한다.


# 2. 새로 배운 내용(코드 위주)
