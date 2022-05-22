문제 : [[3차] 압축](https://programmers.co.kr/learn/courses/30/lessons/17684)

알고리즘 종류 : map

참조 url : 

# 1. 알고리즘 설명

idx 0부터 시작해서 msg의 idx에 해당하는 문자를 일단 문자열로 만든다.

그 후 idx의 + 1부터 시작하는 nextIdx를 두어 문자열에 nextIdx에 해당하는 문자를 넣어주며

map에 해당 문자열이 포함되어있지 않을때까지 nextIdx를 증가시켜준다.

만약 해당 문자열이 포함되어있지 않다면 idx를 nextIdx - 1로 정해주고 일단 끝까지 가지 않고 멈췄기 때문에 해당 문자열이 끝이 아니라는 isEnd를 false로 바꿔준다.

그렇다면 nextIdx로 문자열을 더하는 작업이 종료되면 남아있는건

새롭게 추가되는 문자열(한번도 나오지 않은)과 isEnd=false 혹은 isEnd가 true라면 idx부터 msg 끝까지인 문자열이 남아있게 된다.

isEnd가 false라면 새롭게 추가되는 문자열이 있는데, 새롬게 추가되는 문자열의 끝 문자만 제외하고는 원래 존재하는 문자열(출력해줘야하는 문자열)이기 때문에 subString으로

map에서 가져오고, 새롭게 추가되는 문자열을 map에 넣어준다.

만약 isEnd가 true라면 idx부터 msg의 끝까지를 포함하는 문자열의 값을 출력해주고 종료해준다.

# 2. 새로 배운 내용
