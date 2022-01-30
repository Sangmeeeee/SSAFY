# Info

문제 : [괄호 회전하기](https://programmers.co.kr/learn/courses/30/lessons/76502?language=cpp)

알고리즘 종류 : 문자열, 스택

참조 url :


# 1. 알고리즘 설명

**스택**을 활용하여 **열린 괄호는 push**하고 **닫힌 괄호일 때만 2가지 조건을 검사**한다.

1. 스택이 비었는데 닫힌 괄호가 들어가거나
2. 스택의 top()이 해당 괄호의 짝이 아니라면

해당 문자열은 올바른 괄호 문자열이 아니기 때문에 정답으로 카운트하지 않는다.


처음에는 아래처럼 소, 중, 대괄호 각각에 대한 스택을 만들고 스택이 비었는지 여부를 판단하여 정답을 카운트했다.
```cpp
  bool check(string str) {

	  stack<int> s, m, l;

	  for (int i = 0; i < str.length(); i++) {
		  if (str[i] == '(') s.push(0);
		  if (str[i] == '{') m.push(0);
		  if (str[i] == '[') l.push(0);
		  if (str[i] == ')') { if (s.empty()) return false; s.pop(); }
		  if (str[i] == '}') { if (m.empty()) return false; m.pop(); }
		  if (str[i] == ']') { if (l.empty()) return false; l.pop(); }
	  }

	  if (!s.empty() || !m.empty() || !l.empty())
		  return false;
	  return true;
  }
```
하지만 위의 경우 '{([)}]'와 같이 각각의 올바른 괄호 문자열이 섞여있을 때를 판별하지 못해서 테스트 14를 통과하지 못했다.


# 2. 새로 배운 내용(코드 위주)
