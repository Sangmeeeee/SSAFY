문제 : [GPS](https://programmers.co.kr/learn/courses/30/lessons/1837)

알고리즘 종류 : 다이나믹 프로그래밍

참조 url : https://tech.kakao.com/2017/09/13/code-festival-round-2/

# 1. 알고리즘 설명

dp[i][j]는 i번 노드가 j번째에 왔을때 고쳐야하는 최소 개수의 경로를 뜻한다.

만약 3 -> 6 처럼 j-1번째에서 j번째로 넘어갈 수 없다면 다른 dp[i][j-1]을 이용해서 해결해준다.

![image](https://user-images.githubusercontent.com/24482602/173247255-18a8f7f9-8fea-48d5-8daf-6efd9166ccf2.png)

위와같이 만약 j-1에서 j로 넘어갈 수 없는 두 노드 n1, n2라면 n2와 연결되어있는 노드들을 n3라고 했을 때, dp[n3][j-1]의 값을 이용하여 해결해준다.

위 그림에서는 dp[4][4] -> dp[6][5]를 사용한다.

# 2. 새로 배운 내용
