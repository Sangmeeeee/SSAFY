# https://www.acmicpc.net/problem/14503
# 14503번-로봇 청소기

n, m = map(int, input().split())
x, y, d = map(int, input().split())
arr = [list(map(int, input().split())) for _ in range(n)]
dx, dy = [-1, 0, 1, 0], [0, 1, 0, -1]
cnt, ans = 0, 0

while 1:
    # 현재 위치를 청소함
    if arr[x][y] == 0:
        arr[x][y] = -1
        ans += 1

    # 네 방향 모두 청소가 이미 되어있거나 벽인 경우에는, 바라보는 방향을 유지한 채로 한 칸 후진을 하고 2번으로 돌아간다.
    if cnt == 4:
        nx, ny = x - dx[d], y - dy[d]
        # 네 방향 모두 청소가 이미 되어있거나 벽이면서, 뒤쪽 방향이 벽이라 후진도 할 수 없는 경우에는 작동을 멈춘다.
        if arr[nx][ny] == 1:
            print(ans)
            break
        x = nx
        y = ny
        cnt = 0
        continue

    if d == 0:
        nx, ny = x + dx[3], y + dy[3]
        # 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
        if arr[nx][ny] == 0:
            cnt = 0
            x = nx
            y = ny
        # 청소가 이미 되어있거나 벽인 경우
        elif arr[nx][ny] == -1 or arr[nx][ny] == 1:
            cnt += 1
        d = 3

    elif d == 1:
        nx, ny = x + dx[0], y + dy[0]
        # 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
        if arr[nx][ny] == 0:
            cnt = 0
            x = nx
            y = ny
        # 청소가 이미 되어있거나 벽인 경우
        elif arr[nx][ny] == -1 or arr[nx][ny] == 1:
            cnt += 1
        d = 0

    elif d == 2:
        nx, ny = x + dx[1], y + dy[1]
        # 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
        if arr[nx][ny] == 0:
            cnt = 0
            x = nx
            y = ny
        # 청소가 이미 되어있거나 벽인 경우
        if arr[nx][ny] == -1 or arr[nx][ny] == 1:
            cnt += 1
        d = 1
    else:
        nx, ny = x + dx[2], y + dy[2]
        # 왼쪽 방향에 아직 청소하지 않은 공간이 존재한다면, 그 방향으로 회전한 다음 한 칸을 전진하고 1번부터 진행한다.
        if arr[nx][ny] == 0:
            cnt = 0
            x = nx
            y = ny
        # 청소가 이미 되어있거나 벽인 경우
        elif arr[nx][ny] == -1 or arr[nx][ny] == 1:
            cnt += 1
        d = 2
