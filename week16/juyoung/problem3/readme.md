# Info

문제 : [수식 최대화](https://programmers.co.kr/learn/courses/30/lessons/67257)

알고리즘 종류 : 

참조 url :


# 1. 알고리즘 설명

:round_pushpin: **풀이 과정**  
1. 피연산자와 연산자 목록을 분리해서 저장한다.
2. 연산자의 우선순위에 대한 모든 순열을 만든다.
3. 모든 연산자의 우선순위가 정해지면 그에 맞게 계산한다.

:round_pushpin: **상세 설명**  
**(1)**  
피연산자와 연산자의 목록을 분리할 때는 주어진 입력 `expression`의 문자를 하나씩 꺼내서  
문자가 숫자일 때는 문자열 `str`에 문자를 더해주고,  
연산자일 때는 `str`을 정수로 변환하여 피연산자 벡터에, 연산자는 연산자 벡터에 삽입한다.  
반복문이 끝난 이후에 `str`에 저장된 마지막 숫자를 피연산자 벡터에 삽입해줘야 한다.

**(2)**  
`op`라는 배열에 미리 연산자 3개를 저장해두고  
이를 바탕으로 `prior`이라는 배열에 연산자를 우선순위 순서대로 저장한다.  
그리고 우선순위가 모두 정해졌을 때, `prior`을 사용하여 연산을 수행한다.  
모든 순열에 대해 위 과정을 반복한다.

**(3)**  
정해진 우선순위를 바탕으로 연산을 수행한다.  
연산은 피연산자 벡터와 연산자 벡터에서 연산이 완료된 것은 제거하는 방식으로 이루어진다.  
따라서 연산을 수행하기에 앞서 `copy_num`과 `copy_op`라는 벡터를 만들고,  
각각에 기존에 구해둔 피연산자 벡터와 연산자 벡터를 복사한다.

우선순위가 큰 것부터 처리해야 하기 때문에 첫번째 for문은 우선순위 배열을 탐색하는 for문,  
연산을 수행하기 위해 두번째 for문은 복사한 `copy_num`을 탐색하는 for문이다.  
`prior[i]`와 `copy_op[j]`가 같은 경우에만 연산을 수행하며, 연산의 결과는 `copy_num[j]`에 저장한다.  
연산이 이루어진 후 각 벡터에서 연산이 완료된 부분은 제거해야 하는데,  
`copy_num[j]`에 연산 결과를 저장했으므로 `copy_num`의 `j+1`번째 원소를 지운다.  
마찬가지로 `copy_op`에서 연산이 완료된 연산자인 `copy_op[j]`를 지운다.  
이때 주의할 점은, for문이 `copy_op`를 바탕으로 돌고 있는데 이 벡터의 원소를 하나 지웠으므로  
탐색하는 인덱스인 `j`를 1만큼 감소시켜야 한다는 점이다!

:round_pushpin: **그림**  
![KakaoTalk_20220511_105706608](https://user-images.githubusercontent.com/57346428/167754625-5a7c041e-114f-4c81-8d21-84407cbd149e.jpg)

:round_pushpin: **느낀점(?)**  
벡터에서 `erase()`를 사용하면 지워진 원소 뒤의 모든 원소를 앞으로 당기는 작업을 수행하니까  
내 방법이 비효율적이라고 생각했는데, 풀고 나서 다른 사람 풀이를 보니 나랑 완전 똑같이 풀려있었다.  
그래서 내 방법이 아예 안좋은 방법은 아니구나 하고 안심했다...(아닌가)


# 2. 새로 배운 내용(코드 위주)
