
# Info

  

  

문제 : [이차원 배열과 연산](https://www.acmicpc.net/problem/17140)

  

  

알고리즘 종류 : 문자열, 스택, 재귀 (+ 백트래킹...?)

  

  

참조 url : [내가 예전에 푼 문제](https://neon-snapdragon-743.notion.site/1799-d39c13966a7e4b9ca5d6732f883639f9)

  

  

# 알고리즘 설명

1. 괄호쌍의 인덱스를 구해서 벡터에 저장한다
- '(' 가 나오면 스택에 인덱스를 넣고 ')' 가 나오면 pop해서 두 인덱스에 대한 pair 생성
2. 특정 괄호쌍들을 제외한 문자열의 모든 경우의 수를 재귀적으로 구한다
- 제외된 괄호쌍들은 bool 배열에서 true로 표시됨
3. depth가 3이면 bool 배열에서 false인 곳만 임시 문자열에 추가해서 set에 넣는다
- 이 때, 원래 문자열과 같으면 set에 넣지 않음

  

# 새로 배운 내용
set container  
- 중복이 허용되지 않고 insert를 하면 자동으로 정렬된다.
- iterator로 순차적으로 접근해서 출력할 수 있다.
```c++
set<T> iterator iter;
for(iter = s.begin(); iter != s.end(); iter++){
    cout << * iter << endl;
}
```
이게 귀찮으면 auto를 쓰면 된다.
```c++
set<T> s;
for (auto i : s)
		cout << i << '\n';
}
```
