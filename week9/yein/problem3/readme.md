# Info

문제 : [타일 채우기 3](https://www.acmicpc.net/problem/14852)

알고리즘 종류 : 다이나믹 프로그래밍

참조 url : 없음

# 알고리즘 설명
![image](https://user-images.githubusercontent.com/77979505/160280684-ea4da75d-e36a-43a3-bdf1-b2b71ad63933.png)

1. dp를 n+2의 크기로 선언하고 0으로 채운다.
2. dp[0], dp[1], dp[2] 를 각각 1,2,7로 갱신한다.
3. 만약 n이 2 이하일 경우, dp[n]을 출력하고 프로그램을 종료한다.
4. 3부터 n까지 반복하는 i에 대한 for문을 돌린다. -> dp[i]를 dp[i]=(dp[i-1]*3+dp[i-2]-dp[i-3])%1000000007로 갱신한다.
5. 반복문이 끝난 후 dp[n]%1000000007 출력.

# 새로 배운 내용
