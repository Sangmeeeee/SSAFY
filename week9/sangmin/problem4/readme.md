문제 : [색상환](https://www.acmicpc.net/problem/2482)

알고리즘 종류 : dp

참조 url : 

# 1. 알고리즘 설명

색상환을 경우의 수에 따라 선택하는 개수를 세어주는 문제이다.

N, K가 주어지는데 dp[i][k]의 뜻은 1 ~ i번째 색상환에서 가질 수 있는 경우의 수 k이다.

그렇다면 i번째 색상환이 경우의 수에 포함되냐 안되냐에 따라 나뉜다.

    1. 경우의 수에 포함된다면 i - 2번째 색상환에서 k - 1만큼 가질 수 있는 경우의 수와 같아진다.
    
    2. 경우의 수에 포함되지 않는다면 i - 1번째 색상환에서 가질 수 있는 경우의 수 k와 같아진다.

따라서 dp[i][k] = dp[i - 2][k - 1] + dp[i - 1][k]라고 볼 수 있다.

해당 점화식을 쭉 수행시키면 마지막 dp[N][K]가 나오는데 dp[N][K]를 그대로 사용해서는 안된다.

색상환은 원형이기 때문에 dp[N][K]에는 분명 1번째 색상환과 마지막 N번째 색상환이 맞닿아 있을 경우가 생긴다.

dp[N][K]를 구하는 과정은 문제될게 없다. 무조건 마지막 색상환이 1번째 색상환과 떨어져 있기 때문이다.

그렇다면 dp[N][K]는 이때까지의 정보를 바탕으로 다시 재구성 해줘야한다.

    1. N이 경우의 수에 포함될 때는 2 ~ (N - 2)까지 K - 1만큼 가질 수 있는 경우의 수와 같아진다. 이때까지의 dp의 정의는 1 ~ i까지의 색상환이라고 했는데 2에서 부터 시작하기 위해선 어렵게 생각하면 안된다.
    1번째 색상환이라는건 편의를 위해 1번째 색상환이라 둔거지  1 ~ 4번째 색상환의 경우의 수 dp[4][k]는 따지고 보면 2 ~ 5번째 색상환의 경우의 수와 같다.
    이 특성을 활용해서 2 ~ (N - 2)까지의 경우의 수는 dp[N - 3][K - 1]이 된다.

    2. N이 경우의 수에 포함되지 않을 때는 쉽다. dp[N-1][K]가 된다.

위 두가지를 더한 경우가 정답이 된다.

dp[N][K] = dp[N - 3][K - 1] + dp[N - 1][K];

# 2. 새로 배운 내용