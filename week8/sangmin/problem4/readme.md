문제 : [작업](https://www.acmicpc.net/problem/2056)

알고리즘 종류 : 위상정렬

참조 url : 

# 1. 알고리즘 설명

위상정렬을 통해 노드들을 방문하면서 해당 노드가 가질 수 있는 최대값(이전 노드들까지 오는데 걸린 시간 + 현재 노드에서 걸린 시간)을 구하는 문제이다.

위상정렬에 어느정도 dp 개념을 섞은 문제이다.

현재 노드의 최대값(걸린 시간) = 이전 노드들의 최대값 + 현재 노드에서 걸린 시간이기 때문에 현재 노드까지 왔을때의 걸린 시간을 저장할 수 있는 results 배열과

현재 노드에서 걸리는 시간을 저장하는 times 배열을 사용한다.

위상정렬을 통해 노드들을 방문하면서 results[nextNode](다음 노드까지 걸리는 최대시간)는 results[curNode] + times[nextNode](현재 노드까지의

최대 시간 + 다음 노드에서 걸리는 시간)와 비교해서 더 큰 값을 가지게 된다.

그도 당연할게 모든 작업이 완료해야 다음 작업으로 넘어갈 수 있기 때문에 예를 들어 5번 작업에 2, 3번 작업이 연결되어있다고 생각해보자.

2번 작업은 2초만에 끝나는데 비해 3번 작업은 100초가 경과해야 끝날 수 있다. 2번 작업이 끝나는 시점에서 5번 작업의 최대값은 2초 + 5번 작업에 걸리는 시간이다.

그 후 3번 작업이 끝나는 순간 더 큰 결과를 비교해서 넣어준다. 이런 상황에서 5번작업은 아무리 빨라봤자 100초 후 작업을 시작할 수 있다.

# 2. 새로 배운 내용