문제 : [문자열 잘라내기] ([url](https://www.acmicpc.net/problem/2866))

알고리즘 종류 : set

참조 url : (url)

# 1. 알고리즘 설명(로직위주)

## 문제 이해

문제를 이해하는데 좀 오래걸렸다.(”가장 위의 행을 지워도 테이블의 열을 읽어서 문자열이 중복되지 않는다면, 가장 위의 행을 지워주고 count++ 해라” 를 제대로 이해를 못했음)

30분동안 StringBuilder 배열을 만드는데 애썼다.

Set을 쓸까 Map 을 쓸까 고민하다가 set을 썼다. 중복이 되는경우가 없어야 하는것이 정상적인(?) 코드이기 때문에 Set을 썼다. Map을 썼더라면 <String,Integer>로 value로는 중복 수로 썼을텐데 중복 된다면 바로 탈출해야하고 중복이 얼만큼 되냐는 우리의 관심사가 아니기 때문에 HashMap 보다는 HashSet이 적합하겠다는 생각을 했다.  

### 메모리초과..

문제 풀다가 메모리 초과도 떴었는데 Set 객체를 새로 만들어 주면서 예전의 Set 내용들은 GC대상이 되도록 하여 메모리 초과를 해결했다(그래도 300MB... ㅋ) 
근데 상민이 코드를 보면서 clear를 하는 메서드도 있더라고.. set.clear()를 해줬으면 훨씬 깔끔 했을것 같다.

## 로직

일단 C,R을 받아와주고, 첫번째 라인은 중복인지 아닌지 체크하는데 아무런 영향이 없기에 버려주었다. 

StringBuilder 를 배열로 만들어서 각각 String 을 열로 append 하도록 만들어 주었다. 이후 라인을 돌면서 HashSet을 만들어주어 있는지 체크 하면서 add해주었다. 만약 set에 있다면 중복 된 문자열이 있다는 소리이기에 즉시 flag를 true 로 만들어주고 탈출하여 count를 출력 했다. 

# 2. 새로 배운 내용(코드위주)

## StringBuilder [] sbArr = new sbArr[100];

### 생각 해보니 저건 생성자가 아니겠구나?

```java

public class Main {
    public static void main(String[] args) {
      StringBuilder[] sbArr= new StringBuilder[100]; //이건 생성자가 아니다.
      for(int i=0;i<sbArr.length;i++){
        sbArr[i] = new StringBuilder();
      }
    }
}
```

StringBuilder는 생성할때 StringBuilder sb = new StringBuilder(); 했는데, 저건 생성자가 아님을 나아중에 알았다. 메모리 측면으로는 StringBuilder를 가리키는 참조변수를 100개 만들어준것.(StringBuidler a; StringBuilder b; StringBuilder c; 와 마찬가지이다.)

 얘네들을 객체를 통해서 일일이 생성을 해주어야한다.