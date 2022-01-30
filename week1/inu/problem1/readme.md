# Info

  

문제 : [문자열 폭발](https://www.acmicpc.net/problem/9935)

  

알고리즘 종류 : 문자열

  

참조 url : https://cocoon1787.tistory.com/720

  

# 알고리즘 설명

1. 벡터에 문자열의 문자를 하나씩 넣는다.

2. 벡터의 크기가 폭발 문자열의 길이보다 길어지면 폭발 문자열이 벡터에 포함되어 있는지 검사한다.
- 이 때, 현재 벡터의 인덱스에서 폭발 문자열의 길이만큼 뺀 위치부터 폭발 문자열의 앞부분과 차례대로 비교

3. 포함되어 있으면 폭발 문자열의 길이만큼 pop을 한다.

5. 벡터의 크기에 따라 남은 문자열을 출력하거나 FRULA를 출력한다.

# 새로 배운 내용
원래는 string 클래스에 있는 find 메서드로 폭발 문자열의 위치를 찾아서 자르고 붙이는 걸 반복했는데
바로 시간초과가 났다. 최대 문자열 길이가 백만이라서 그런 것 같다. 항상 입력받는 값의 범위를 확인하자.
```c++
#include <iostream>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string origin, str;
	int s = 0, e = 0;

	cin >> origin;
	cin >> str;

	while (1) {
		int idx = origin.find(str);

		if (idx == string::npos) {
			if (origin.length() != 0)
				cout << origin;
			else
				cout << "FRULA";

			return 0;
		}
		origin[2] = '\0';
		string front = origin.substr(0, idx);
		string end = origin.substr(idx + str.length(), origin.length());

		origin = front.append(end);
	}
}
```
