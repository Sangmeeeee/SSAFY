# Info

문제 : [오픈채팅방](https://programmers.co.kr/learn/courses/30/lessons/42888)

알고리즘 종류 : 구현

참조 url : 없음

# 알고리즘 설명
1. record를 순차적으로 탐색하면서 공백을 기준으로 split 해준 후 user에 저장해준다.
2. user의 첫번째 인덱스의 값이 'Enter'이거나 'Change'라면 users[유저아이디]의 값을 닉네임으로 저장해준다.
3. 또 다시 record를 순차적으로 탐색하면서 'Enter'일 때는 닉네임을 출력해주고 '님이 들어왔습니다.'라는 문자열을 붙여준다.
4. 'Leave'일 때는 닉네임을 출력해주고 '님이 나갔습니다.'라는 문자열을 붙여준다.

# 새로 배운 내용
