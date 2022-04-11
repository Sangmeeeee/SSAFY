#https://www.acmicpc.net/problem/14938
#14938번-서강그라운드
n,m,r = map(int,input().split())
item =list(map(int,input().split()))
INF = int(1e9)
f = [[INF]*(n+1) for _ in range(n+1)]
for _ in range(r):
    a,b,c = map(int,input().split())
    f[a][b]=c
    f[b][a]=c

for k in range(1,n+1):
    for a in range(1,n+1):
        for b in range(1,n+1):
            f[a][b]=min(f[a][b],f[a][k]+f[k][b])
result=0
for i in range(1,n+1):
    cnt=item[i-1]
    for j in range(1,n+1):
        if f[i][j]<=m: 
            cnt+=item[j-1]
    result=max(result,cnt)
print(result)