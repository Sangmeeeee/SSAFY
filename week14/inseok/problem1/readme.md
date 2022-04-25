문제:  [전화번호 목록](https://www.acmicpc.net/problem/5052)

알고리즘 종류 : Trie(트라이)

참조 url : 

[[자료구조 trie 트라이](https://yabmoons.tistory.com/379)]

[[자료구조 Trie 만드는법 자바 코드 설명]](https://the-dev.tistory.com/3)

# 1. 알고리즘 설명(로직위주)

## Trie 자료구조 설명

### Trie

이제 자료구조가 좀 헷갈리긴 해서 문제를 정리를 해둬야겠다. 생각했다.

### Trie 자료구조

Trie 는 “문자열을 빠르게 탐색하게 해주는 자료구조” 이다. 문자열을 관리하는 방법 중 하나.

### Trie 작동 원리

주어진 문자열을 이루고 있는 문자를 **앞에서 부터 하나씩 노드를 생성** 해 가면서 만들어진다.

**반복된 재귀 호출**을 통해 생성한다.

### Trie 생성 과정

1. 주어진 문자열에서 현재 문자를 가져온다.
2. 현재 문자로 이루어진 노드가 존재한다면, 그 노드로 그 다음 문자열을 탐색 하고 , 노드가 없다면 그 노드를 새로 할당 받은 후, 해당 노드를 통해 다음 문자열을 탐색한다.
3. 문자열의 마지막이 될 때 까지 위의 과정을 반복한다.

솔직히 이렇게 쓰여있는데 뭔 소린지를 모르겠더라.. 그래서 그림을 좀 보면서 이해를 했고, 문제를 봤다.

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/fe1b2812-2256-4d3d-8105-f06d87fa3665/Untitled.png)

### TrieNode 기본 자료구조 (JAVA)

```java
public class TrieNode { 
	// [ 변수 ] 
	// 자식 노드 맵 
	private Map<Character, TrieNode> childNodes = new HashMap<>(); 
	// 마지막 글자인지 여부 
	private boolean isLastChar; 
}

출처: https://the-dev.tistory.com/3 [DevLogs]
```

클래스 자료구조를 보니 무슨 뜻인지 더욱 알겠더라.

### Trie 기본 자료구조 (JAVA)

```java
public class Trie { 
		public TrieNode rootNode;
		public Trie() {
		    this.rootNode = new TrieNode();
		}
		//insert(String)
		void insert(String str){/*생략*/}
		boolean find(){/*생략*/}
		
}

```

### 일관성 체크에 대한 생각.

별표를 표시함으로써 문자열의 끝을 표시 한다고 하더라. 문제에 따르면 일관성 있는 번호라면 별표는 무조건 마지막에 있는 형태가 될거라고 생각했음.

### 일관성 체크

insert 를 할때 마다 체크를 하도록 했고, 처음에는 String 을 넣어줄때 타고 들어가다가, isLastChar 가 True 인 경우에 일관성이 무너진 경우라 체크를 했다.

다른 방식으로 일관성이 무너지는 경우도 있다. 바로, insert 를 모두 한 상태에서 그 뒤에 childNode 가 있는 경우도 일관성이 무너진 경우로 체크를 해주어야한다.

# 2. 새로 배운 내용(코드위주)

### 문제 해결

별표를 표시함으로써 문자열의 끝을 표시 한다고 하더라. 문제에 따르면 일관성 있는 번호라면 별표는 무조건 마지막에 있는 형태가 될거라고 생각했음.

### computeIfAbsent() 메서드

이 메서드는 java8 에서 지원하는 메서드인듯.

hashMap과 같은 key, value가 있는 자료구조에서 쓰이는 메서드이다. 

두개의 인자가 들어오는데 첫번째 인자는 해당 key 가 있으면, value 를 반환, key 가 없다면 두번째 인자(함수) 를 실행 하도록 하는 메서드이다.