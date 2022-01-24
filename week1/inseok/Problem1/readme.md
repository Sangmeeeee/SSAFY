어떻게 쓰는지 몰라서 다들 양해를 부탁드리며 이렇게 시작해봅니다.

1. 문제 
  9935 문자열 폭발 (https://www.acmicpc.net/problem/9935)
2. 알고리즘 종류
  * Stack
  * 
3. 참조 url
4. 사용해본 도구
  * [Class] StringBuilder
  *   String 보다 추가 삭제가 유리하다고 해서 써봤음. 이 문제에서 엄청난 이들을 본 느낌은 없지만, 
  *   [method] append() : StringBuilder에 추가 하는 메서드
  * [Class] Stack<T>
  *   도중에 문제 풀다가 다 갈아 엎고 써보기로 결정. push, pop 에 용이. 근데 top을 가리키는 메서드가 없어서 불편 하더라.
5. 로직 설명
    Static Class Block 
      내가 만든 클래스, idx는 String 의 위치, bIdx 는 bomb의 idx 위치를 한꺼번에 스택에 저장 하기 위해 만든 클래스. 
    Stack
      newSt 를 돌면서 bombSt 비교대상부분과 같은 문자를 가지고 있을때 newSt의 인덱스(idx)와 bomSt 인덱스(bIdx)를 Class Block 으로 묶어서 Stack에 넣어줬다. 비교를 하며 bombIdx를 키우다가 bomSt첫 부분과 같을떄는 Block을 만들어 스택에 넣어 준 뒤, bombIdx를 1으로 두어 두번째 부터 비교 하도록 했다. 만약 비교를 했는데 폭발 하지 않는경우에는 Stack을 완전히 비워주며 bombIdx도 초기화 해주었다.
    String newSt : String 첫번째 내용물. 
    String bombSt : String 두번째 내용물.
    int bombIdx : bombSt에서 비교위치를 알려준다. 
6. 시간복잡도
    
    
7. 공부 해봐야 할것
  * 추가 삭제가 유리하다고 했는데 메모리 측면인지, 속도측면인지 공부를 해두면 좋겠다.
