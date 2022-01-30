# 1. 알고리즘 설명(로직위주)

## 문제 이해

회전이란 [](){} 가 있다면 ](){}[ , (){}[] , ){}[]( .... 이렇게 하나씩 문자열의 제일 앞자리 문자를 제일 위로 옮기는것을 회전이라 한다. 예시를 보면서 이해를 했음.

## check 함수(스택이용)

week1 문제1 [문자열폭발]([https://www.acmicpc.net/problem/9935](https://www.acmicpc.net/problem/9935)) 문제 와 비슷하게 괄호가 잘 묶여있는지 보는 문제이다. 유사하게 스택을 이용했고, 인덱스가 필요하진 않기에 순수하게 어느 괄호가 담기는지를 결정 할수 있도록 Integer형이 담기게 설정했다.(0:”(” , 1:”[” , 2: “[” 담기도록) 

문자열을 처음부터 끝까지 돌면서 열리는 괄호가 오면 스택에 넣어준다. 닫히는 괄호가 왔을때 스택이 비거나,  스택 최상위에 있던녀석을 pop 했을때 맞지 않는 괄호가 나온다면 비정상적 문자열이기에 flag을 true로 설정 해준다.

만약 flag가 true 면 비정상 문자열, flag가 false면 정상 문자열이다.

또한 효율성을 위해 falg가 true 이면 더이상 해당 문자열을 비교할 필요없기 때문에 문자열을 보던 for문을 break 해준다.이면 

flag가 true 이면 return 0, false이면 return 1  해주어 추후에 answer 변수에 더해준다.

## 문자열 회전

문자열을 효율적(새로 배운내용에 적겠다.)으로 회전 시키기 위해 StringBuilder에 문자열을 담았다.

문자열을 회전 하면서 check함수를 실행해야한다.

check함수 실행 후, 문자열을 다 보았기에 회전한 문자열을 봐주어야하기에 문자열의 앞에문자를 제거하(deleteCharAt)고 뒤에다가 붙여준다(append).

# 2. 새로 배운 내용(코드위주)

## String vs. StringBuilder 의 차이 [참조]([https://ifuwanna.tistory.com/221](https://ifuwanna.tistory.com/221))

![Untitled]("https://user-images.githubusercontent.com/49578522/151687844-a77bc0e9-f5bf-44c9-a359-a122dcb8b984.png")

String은 Immutable, 나머지는 Mutable이다. 

### mutable 한 String, 어떤 특징을 가지고 있나?

```
String string = new String("Hello");
string+= " world";
```

String 의 경우 이렇게 수정을 해주고 성공적으로 실행 된다. 그러나 메모리 측면으로 생각을 해보면 그닥 효율적이지는 못하다. 

![Untitled](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/59e5c091-6573-49c3-867e-ba1c17ecf7fc/Untitled.png)

이런식으로 초반에 만들어졌던 Hello에 world 만 붙는것이 아니라  새로운 메모리 영역을 만들어 거기에 새로운 문자열을 저장 하기에 기존의 hello 의 문자열 공간이 힙 영역에 계속 남아 있게 되고 이는 GC 제거 대상이 된다. 그래서 이는 program 의 힙 공간을 부족하게 할 우려가 크고 이는 program 의 성능에 영향을 줄 수있다. 

따라서 String 을 통한 잦은 수정을 할경우 mutable 한 성질을 띄기에 이는 합리적이지 못하다.

### StringBuilder와 String Buffer 의 차이

String Builder와 String Buffer의 차이는 동기화의 키워드 지원 유무로 멀티 쓰레드의 일때 안전성에 차이가 난다.

StringBuilder는 멀티쓰레드 환경에서 안전성 보장이 안되기에 적합 하지 않다.  

StringBuffer 는 동기화 키워드를 지원하기에 멀티쓰레드 환경에 적합하다.그러나  동기화 키워드를 체크하는 만큼 StringBuilder보다 속도가 느리다고 한다.

따라서 싱글쓰레드에서 빠른 속도로 이용 하고 싶을경우 StringBuilder 이용.

멀티쓰레드 환경이라면 느리더라도! 안전성 보장된 StringBuffer이용 하자
