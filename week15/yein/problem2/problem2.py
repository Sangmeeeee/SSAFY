#프로그래머스-오픈채팅방

def solution(record):
    
    answer = []
    users = dict()
    
    for r in record:
        user = r.split(' ')
        if user[0] =='Enter':
            users[user[1]] = user[2]
        elif user[0] == 'Change':
            users[user[1]] = user[2]
    
    for r in record:
        user = r.split(' ')
        if user[0] == 'Enter':
            answer.append(users[user[1]]+'님이 들어왔습니다.')
        elif user[0] == 'Leave':
            answer.append(users[user[1]]+'님이 나갔습니다.')

    return answer