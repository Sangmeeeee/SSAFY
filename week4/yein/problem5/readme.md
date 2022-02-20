# Info

문제 : [단어 변환](https://programmers.co.kr/learn/courses/30/lessons/43163)

알고리즘 종류 : dfs

참조 url : 없음

# 알고리즘 설명

1. 문제에서의 가장 중요한 조건은 한 번에 한 개의 알파벳만 바꿀 수 있고 words에 있는 단어로만 변환할 수 있다.
2. 그렇게 해서 begin에서 target으로 변환하는 가장 짧은 변환 과정을 찾아야한다.
3. 우선 target 단어가 words에 없을 경우도 있기 때문에 target이 words에 있는지 체크해준 후 dfs를 실행해준다.
4. 파라미터 값으로 begin, target, words 그리고 변환 과정을 세어줄 변수 cnt로 선언해준다.
5. zip을 사용하며 현재 words와 begin 단어의 알파벳 하나하나 검사해주며 차이를 세어준다.
6. 만약 한 개 이상의 알파벳이 차이난다면 break 한다. 그렇지 않다면 방문 체크를 해주는 리스트 visited에 단어를 append해주고 다시 dfs를 실행시켜준다.
7. 계속해서 탐색하며 변환하는 가장 짧은 변환 과정을 찾아주고 그 값을 return해준다.

# 새로 배운 내용