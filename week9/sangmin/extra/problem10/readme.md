문제 : [RGB거리 2](https://www.acmicpc.net/problem/17404)

알고리즘 종류 : dp

참조 url : 

# 1. 알고리즘 설명

dp[i][0]을 i번째 집을 빨강으로 칠했을때의 최소비용, dp[i][1]을 i번째 집을 초록으로 칠했을때의 최소비용, dp[i][2]을 i번째 집을 파랑으로 칠했을때의 최소비용이라고 정의한다.

맨 처음 집을 빨강 -> 초록 -> 파랑 순으로 칠하고 시작하며 그렇게되면 dp[1][color]는 칠한 색을 제외하고는 1000 * 1000 + 2로 채워준다.

dp[i][0]은 이전 초록 혹은 파랑중에서 작은 값 + i번째 집을 빨강으로 칠할때의 비용으로 정한다.

그렇다면 마지막에는 모든 color로 끝날때의 최소값이 나오게 되는데 첫번째 집과 달라야하기 때문에 첫번째 집의 색깔을 제외하고 둘 중 작은값이 답이된다.(빨강, 초록, 파랑 모든 경우에 대해)

# 2. 새로 배운 내용