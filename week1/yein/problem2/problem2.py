#https://www.acmicpc.net/problem/17140
#17140번-이차원 배열과 연산

from collections import Counter
from copy import deepcopy
import sys

input = sys.stdin.readline
r,c,k = map(int,input().split())
A = [list(map(int,input().split())) for _ in range(3)]
ans = 1
n ,m = 3, 3

def calc (A,a):
    max_len = 0
    for i in range(len(A)):
        for j,v in sorted(Counter(A[i]).items(),key = lambda x:(x[1],x[0])):
            if j!=0:
                a[i].append(j)
                a[i].append(v)
        max_len = max(max_len,len(a[i]))

    for i in range(len(a)):
        for _ in range(max_len-len(a[i])):
            a[i].append(0)

if r<=len(A) and c<=len(A) and A[r-1][c-1]==k: print(0)
else:
    while ans<=100:
        if n<m: # C 연산
            a = [[] for _ in range(m)]
            A = list(map(list, zip(*A)))
            calc(A,a)
            a = list(map(list,zip(*a)))
        else:   # R 연산
            a = [[] for _ in range(n)]
            calc(A,a)

        if r<=len(a) and c<=len(a[0]) and a[r-1][c-1]==k: 
            print(ans)
            break
        
        ans+=1
        n ,m = len(a), len(a[0])
        A = deepcopy(a)
    else: print(-1)