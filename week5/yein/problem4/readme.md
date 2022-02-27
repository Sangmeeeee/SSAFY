# Info

문제 : [탈출](https://www.acmicpc.net/problem/3055)

알고리즘 종류 : BFS

참조 url : 없음

# 알고리즘 설명

1. 티떱숲의 지도를 2차원 배열로 입력받으며 고슴도치의 위치를 발견하면 deque에 appendleft를 해주어 고슴도치가 먼저 이동할 수 있도록 한다. 그리고 물의 위치는 append로 해준다.
2. 이동한 시간을 저장할 배열 visited를 선언하여 고슴도치가 이동할 때 마다 시간을 저장해준다.
3. BFS를 돌면서 4방 탐색을 해준다.
4. 현재 물이 이동을 하는 거면 고슴도치의 위치나 비어있는 곳으로 가야하므로 찾아서 append 해주고 이동한 위치를 물로 바꿔준다.
5. 고슴도치가 이동을 하는 거면 비어있는 곳으로만 이동할 수 있으므로 비어있는 곳일 때 이동을 해주고 visited[nx][ny] = visited[x][y]+1 하여 시간을 +1 추가해준다.
6. 만약에 고슴도치가 이동을 하는 곳이 비버의 소굴이면 시간을 +1 해주고 바로 return 해준다.
7. 시간이 0이 아닐 땐 그대로 정상으로 출력하고 0이라면 "KAKTUS"를 출력한다. 

# 새로 배운 내용