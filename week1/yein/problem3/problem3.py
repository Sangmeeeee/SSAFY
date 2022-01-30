#https://www.acmicpc.net/problem/2800
#2800번-괄호 제거
from itertools import combinations

s = input()
stack = []
array = []
ans = set()
for i in range(len(s)):
    if s[i]=='(': stack.append(i)
    elif s[i] ==')':
        num = stack.pop()
        array.append((num,i))

for i in range(1,len(array)+1):
    for comb in combinations(array,i):
        rm_index = []
        rm_result = []
        for c in comb:
            a,b = c
            rm_index.append(a)
            rm_index.append(b)
        for j in range(len(s)):
            if j not in rm_index: rm_result.append(s[j])
        ans.add(''.join(rm_result))    

print(*sorted(ans),sep='\n')