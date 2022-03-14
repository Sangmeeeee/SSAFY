length, width, height = map(int, input().split())
n = int(input())
cube = [list(map(int, input().split())) for _ in range(n)]
volume = length * width * height
ans = 0
before = 0
cube.sort(reverse=True)

for w, cnt in cube:
    before <<= 3
    v = 2 ** w
    maxCnt = (length // v) * (width // v) * (height // v) - before
    maxCnt = min(cnt, maxCnt)
    ans += maxCnt
    before += maxCnt

if before == volume:
    print(ans)
else:
    print(-1)