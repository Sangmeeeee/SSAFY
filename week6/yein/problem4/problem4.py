# https://www.acmicpc.net/problem/12904
# 12904번-A와 B

s = input()
t = input()
while s != t:
    if t[-1] == 'A':
        t = t[:-1]

    elif t[-1] == 'B':
        t = t[:-1]
        t = t[::-1]

    if (len(t) == len(s) and s != t) or len(t) < len(s):
        print(0)
        break

else:
    print(1)
