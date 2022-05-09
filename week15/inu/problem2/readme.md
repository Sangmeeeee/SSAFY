# Info

  

문제 : [오픈채팅방](https://programmers.co.kr/learn/courses/30/lessons/42888)

알고리즘 종류 : map

참조 url : [요기](https://ssungkang.tistory.com/entry/C-string-%EB%AC%B8%EC%9E%90%EC%97%B4-%EB%82%98%EB%88%84%EB%8A%94-split)

  

# 알고리즘 설명 
1. uid와 닉네임을 쌍으로 저장하는 map을 하나 선언한다.
    - `map<string, string> nickname`
2. record의 string을 공백을 기준으로 나누는 함수를 만들어 split한다. 나누어진 토큰들은 `vector<string> token`에 저장된다.
    - `token[0]` : "Enter" or "Leave" or "Change"
    - `token[1]` : uid
    - `token[2]` : nickname
    - 이 때 각 `token`은 `vector<vector<string>> tokens`에 저장된다.
3. `token[0]`이 "Enter" 또는 "Change"일 때 닉네임이 변경되므로 해당 메시지가 나오면 해당 uid의 닉네임을 변경해준다.
    -  `nickname[token[1]] = token[2]`
4. `tokens`를 순회하면서 token[0]에 따라 `answer`에 출력될 메시지를 저장한다.
    - `answer.push_back(nickname[token[1]] + "님이 ~~")`

   
# 새로 배운 내용
c++에는 string을 split하는 함수가 따로 없어서 어떻게 하는지 찾아봤는데 생각보다 간단한 구현으로 split이 가능했다.  
`sstream` 헤더파일에 있는 `stringstream`이라는 클래스를 이용하면 된다.
자바의 `BufferedReader`와 비슷하다고 느꼈는데 차이점이 있다면 `stringstream`은 string을 입력으로 받는 스트림 클래스라는 것이다.  
스트림이기 때문에 `getline`을 사용할 수 있다.
```c++
vector<string> split(string input, char delimeter) {
    vector<string> token;
    stringstream ss(input);
    string temp;

    // delimeter 기준으로 ss를 잘라 temp에 저장
    while (getline(ss, temp, delimeter)) {
        token.push_back(temp);
    }

    return token;
}
```
