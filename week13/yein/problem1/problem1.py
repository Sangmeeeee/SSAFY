#https://www.acmicpc.net/problem/1043
#1043번-거짓말
n,m = map(int,input().split())
t = list(map(int,input().split()))[1:]
parent = [0]+list(range(1,n+1))
party = []

def find_parent(parent,x):
    if parent[x]!=x:
        parent[x] = find_parent(parent,parent[x])
    return parent[x]

def union(a,b):
    a = find_parent(parent,a)
    b = find_parent(parent,b)

    if a in t and b in t: return

    if a in t: parent[b] = a
    elif b in t: parent[a] = b
    else:
        if a>b : parent[a] = b
        else: parent[b] = a

for _ in range(m):
    p = list(map(int,input().split()))
    party.append(p[1:])
    for i in range(1,p[0]): union(p[i],p[i+1])

ans = 0

for i in range(m):
    for p in party[i]:
        if find_parent(parent,p) in t: break
    else: ans+=1

print(ans)