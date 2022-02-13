#https://www.acmicpc.net/problem/2866
#2866번-문자열 잘라내기

r,c = map(int,input().split())
s = [input() for _ in range(r)]

if len(set(s[-1]))==len(s[-1]): print(r-1)
else:
    plus = ['']*c
    ans = 0
    for i in range(r-1,-1,-1):
        for j in range(c):
            plus[j]+=s[i][j]
        if len(set(plus))!=c: ans=i
    print(ans-1)
