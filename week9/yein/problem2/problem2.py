#https://www.acmicpc.net/problem/9251
#9251번-LCS

a = " "+input()
b = " "+input()
n,m = len(a),len(b)
dp = [[0]*m for _ in range(n)]

for i in range(1,n):
    for j in range(1,m):
        if a[i] == b[j]:dp[i][j]=dp[i-1][j-1]+1
        else: dp[i][j] = max(dp[i-1][j],dp[i][j-1])

print(dp[-1][-1])