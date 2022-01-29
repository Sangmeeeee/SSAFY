# Info

문제 : [Contact](https://www.acmicpc.net/problem/1013)

알고리즘 종류 : 문자열, 정규 표현식

참조 url : https://suri78.tistory.com/270


# 1. 알고리즘 설명
아래와 같이 크게 2가지 경우로 나눠서 풀었다.

1. 현재 문자가 ‘0’인 경우 **(01 검사)**
    1. 다음 문자가 ‘1’일 때
    2. 다음 문자가 ‘1’이 아닐 때 ⇒ 패턴이 아님
2. 현재 문자가 ‘1’인 경우 **(100+1+ 검사)**
    1. 다음에 ‘0’이 2개 이상 나올 때 (여기까지 100)
        1. 다음에 ‘1’이 1개만 나올 때
        2. 다음에 ‘1’이 2개 이상 나올 때
        3. **다음에 ‘1’이 2개 이상 나오고 “00”이 나올 때 ⇒ 2로 돌아가서 100+1+ 검사** 
    2. 다음에 ‘0’이 1개만 나올 때 ⇒ 패턴이 아님

2-i-a = 1001으로 끝나거나 1001 이후 01 패턴이 이어지는 경우
2-ii-b = 100111과 같이 끝나거나 100111 이후 01 패턴이 이어지는 경우
2-iii-c = 10011001이나 1001111001처럼 100+1+ 패턴이 반복되는 경우


# 2. 새로 배운 내용(코드 위주)

### <regex> 정규 표현식

regex 인스턴스를 생성하여 생성자에 검사할 형식을 인수로 넘긴다.

- 사용법
    - `regex re(”정규식”)`
        - `re`는 해당 정규식을 입력받는 정규식 인스턴스가 된다.
    - `std::regex_match(str, re)`
        - 검사할 형식으로 초기화한 regex 타입의 인스턴스인 `re`와 `str`을 비교하여 올바른 형식인지 검사 후 true, false를 리턴하는 함수이다.
        - 즉, **정규식 패턴 `re`가 입력된 문자열 `str`에 존재하는지 검사**한다.
    
    ```cpp
    string s;
    regex re("(100+1+|01)+");
    
    cin >> s;
    
    if (regex_match(s, re)) cout << "YES\n";
    else					cout << "NO\n";
    ```
    
- 정규식 형식
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/0e49f8f5-0b83-4941-ae06-1f062b255901/Untitled.png)
    
    ![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/aa4042a7-f604-4b4f-a58b-cd35d5eac20a/Untitled.png)

- [참고](https://ansohxxn.github.io/cpp/chapter18-5/)
