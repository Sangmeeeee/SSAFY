#https://www.acmicpc.net/problem/1038
#1038번-감소하는 수
from itertools import combinations
target = int(input())
dicrease_num = []
for i in range(1,11):
    for comb in combinations(range(0,10),i):
        dicrease_num.append(int(''.join(map(str,sorted(comb,reverse=True)))))
dicrease_num.sort()
print(dicrease_num[target] if target<len(dicrease_num) else -1)