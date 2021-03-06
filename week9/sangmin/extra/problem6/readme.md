문제 : [암호코드](https://www.acmicpc.net/problem/2011)

알고리즘 종류 : dp

참조 url : 

# 1. 알고리즘 설명

생각보다 생각할게 많았던 문제다.

현재 위치의 수가 0이냐 아니냐에 따라서 나뉘고 0이 아니더라도 26안에 들어가냐 안들어가냐에 따라 나뉘었다.

dp[i]는 i번째 수까지 복호화 시켰을때 나올 수 있는 경우의 수이다.

그렇다면 위에서 말한것처럼 i번째수가 0이냐, 아니냐, 0이 아닐경우 26안에 들어갈 경우에 따라 나뉜다.

    1. i번째가 0일경우 -> i - 1번째를 보고 1이나 2일경우(10, 20) dp[i] = dp[i - 2]를 해준다. (10이나 20일경우 반드시 2칸을 차지하기 때문)

    2. i번째가 0이지만 i - 1번째가 1이나 2가 아닐 경우(00, 30) -> 어떤 경우라도 복호화할 수 없기 때문에 0이된다.

    3. i번째가 0이 아니고, i와 i - 1번째를 봤을때 10이상 26이하일경우 경우 -> dp[i] = dp[i - 1] + dp[i - 2]를 해준다. 10이상 26이하의 수는 경우에따라 1자리 숫자 2개(dp[i - 1]) 혹은 2자리 숫자 1개(dp[i-2])로 취급되기 때문에 두 경우의 수를 더해준 경우가 된다.

    4. i번째가 0이 아니고, i와 i - 1번째를 봤을때 1이상 9이하, 27 이상일 경우 -> dp[i] = dp[i - 1]를 해준다. 해당 경우의 수는 추가되는 수가 반드시 한자리로 읽히기 때문에 dp[i - 1]과 같다.

위의 4가지 경우를 잘 나누어서 마지막 까지 해주면 정답이 나온다.

# 2. 새로 배운 내용