문제 : [중량제한](https://www.acmicpc.net/problem/1939)

알고리즘 종류 : 유니온파인드

참조 url :

# 1. 알고리즘 설명

[세부](https://www.acmicpc.net/problem/13905) 문제와 똑같다.

한번에 옮길 수 있는 중량의 최대값을 구하기 위해선 MST(Minimum Spanning Tree)를 만들어 줘야햔다.

더 들어가 MST를 만들고 나면 해당 MST를 따라 값을 계속해서 업데이트 해가며 시작 노드부터 끝 노드까지 탐색해줘야한다.

dist[i]를 시작 노드에서 해당 i 노드까지의 거리라고 두었을때 시작 노드에서부터 bfs를 돌면서

해당 노드를 from이라 두고 from과 연결되어 있는 노드들을 to라고 뒀을 때,

dist[to] = Math.min(dist[from], edge[from][to])로 업데이트 해주면서 bfs를 진행해주고

끝 노드가 업데이트 되지 않았을 경우 갈수 없고 업데이트 되었다면 출력해준다.

# 2. 새로 배운 내용

